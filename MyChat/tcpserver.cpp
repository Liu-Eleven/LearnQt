#include "tcpserver.h"

TcpServer::TcpServer(QWidget *parent)
    : QWidget(parent)
{
    CreateUi();
    resize(158,100);
}

TcpServer::~TcpServer()
{

}


void TcpServer::CreateUi()
{
    IpLabel = new QLabel(tr("Ip:"));
    PortLabel = new QLabel(tr("Port:"));

    QLabel *IpValue = new QLabel(tr("192.168.1.1"));
    QLabel *PortValue = new QLabel(tr("6108"));

    QuitBtn = new QPushButton(tr("Quit"));//Quit\nEnrol
    //QuitBtn->setStyleSheet("QPushButton{text-align:right}");//设置按钮字体对齐方式
    QuitBtn->setStyleSheet("QPushButton{background-color:qconicalgradient(cx:0.5,cy:0.5,angle:0,stop:0.368182rgba(198,198,198,75))}");

    MainLayout = new QGridLayout;
    MainLayout->addWidget(IpLabel,0,0,1,1);
    MainLayout->addWidget(IpValue,0,1,1,1);
    MainLayout->addWidget(PortLabel,1,0,1,1);
    MainLayout->addWidget(PortValue,1,1,1,1);
    MainLayout->addWidget(QuitBtn,2,0,1,2);

    connect(QuitBtn,SIGNAL(clicked()),this,SLOT(close()));

    Server = new QTcpServer(this);

    connect(Server,SIGNAL(newConnection()),this,SLOT(SendMessage()));

    if( !Server->listen() )
    {
        QMessageBox::about(this,tr("Clue on"),tr("Listen error"));
        return ;
    }

   QList<QHostAddress> AddrList = QNetworkInterface::allAddresses();

   QString StrAddr;

   foreach(QHostAddress addr , AddrList)
   {
       if(addr != QHostAddress::LocalHost &&
               addr.toIPv4Address())
           StrAddr = addr.toString();
   }

   IpValue->setText(StrAddr);

   //把段口号转换成字符串
   QByteArray I_port = QByteArray::number(Server->serverPort());
   PortValue->setText(QString(I_port));

   fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
            << tr("You've got to think about tomorrow.")
            << tr("You will be surprised by a loud noise.")
            << tr("You will feel hungry again in another hour.")
            << tr("You might have mail.")
            << tr("You cannot kill time without injuring eternity.")
            << tr("Computers are not intelligent. They only think they are.");



   setLayout(MainLayout);
}

void TcpServer::SendMessage()
{
   if(Server->hasPendingConnections() )
   {
        //QTcpSocket * QTcpServer::nextPendingConnection () [virtual]
        //返回一个已经处于连接上的QTcpSocket对象， 该对象是该server的孩子， 意味着当该server被删除时， 会自动删除该对象。
        //通常在使用完该对象后， 显示的删除它， 可以避免浪费内存
        QTcpSocket *socket = Server->nextPendingConnection();

         //QByteArray: 提供一个字节数组
        QByteArray array;

        //QDataStream: 针对输入输出设备操作字节数组

        QDataStream stream(&array,QIODevice::WriteOnly);

        stream << fortunes.at(qrand()%fortunes.size());
        //把byteArray的内容写入到设备中； 返回实际写入的字节数； 如果发生错误返回-1
        socket->write(array);

        //void QAbstractSocket::disconnectFromHost ()
        //试图关闭该socket；如果还有数据在等待写入， 则QAbstractSocket会进入状态ClosingState，
        //直到所有数据被写入。 最后会进入状态UnconnectedState, 同时发出信号disconnected()
        socket->disconnectFromHost();

        //socket发出信号disconnected()后， 调用函数deleteLater()
        //deleteLater()发出删除该对象的调度计划
        connect(socket,SIGNAL(disconnected()),socket,SLOT(deleteLater()));
   }

}

