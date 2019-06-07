#include "tcpclient.h"

TcpClient::TcpClient(QWidget *parent)
    : QDialog(parent)
{
    CreateUi();
}

TcpClient::~TcpClient()
{

}

void TcpClient::CreateUi()
{
    QFont font("ZYSong18030",12);
    setFont(font);

    setWindowTitle(tr("TCP 客户端"));

    QVBoxLayout *vbMain = new QVBoxLayout;

    ListWidgetContent = new QListWidget;


    QHBoxLayout *hb1 = new QHBoxLayout;
    LineEditSend = new QLineEdit;
    hb1->addWidget(LineEditSend);

    SendBtn = new QPushButton(tr("发送"));
    hb1->addWidget(SendBtn);



    QHBoxLayout *hb2 = new QHBoxLayout;
    labelUser = new QLabel(tr("用户名:"));
    hb2->addWidget(labelUser);

    LineEditUser = new QLineEdit;
    hb2->addWidget(LineEditUser);

    QHBoxLayout *hb3 = new QHBoxLayout;
    labelServerIP = new QLabel(tr("服务器:"));
    hb3->addWidget(labelServerIP);

    LineEditServerIp = new QLineEdit;
    hb3->addWidget(LineEditServerIp);

    QHBoxLayout *hb4 = new QHBoxLayout ;
    LabelPort = new QLabel(tr("端口号:"));

    hb4->addWidget(LabelPort);

    LineEditPort = new QLineEdit ;
    hb4->addWidget(LineEditPort);



    EnterBtn = new QPushButton(tr("进入"));


    connect(EnterBtn,SIGNAL(clicked()),this,SLOT(slotEnter()));
    connect(SendBtn,SIGNAL(clicked()),this,SLOT(slotSend()));

    ServerIP = new QHostAddress;
    port = 6108;
    LineEditPort->setText(QString::number(port));

    status = false;
    setLayout(vbMain);

    QList<QHostAddress> AddrList = QNetworkInterface::allAddresses();

    QString StrAddr;

    foreach(QHostAddress addr , AddrList)
    {
        if(addr != QHostAddress::LocalHost &&
                addr.toIPv4Address())
            StrAddr = addr.toString();
    }
    LineEditServerIp->setText(StrAddr);



    vbMain->addWidget(ListWidgetContent);
    vbMain->addLayout(hb1);
    vbMain->addLayout(hb2);
    vbMain->addLayout(hb3);
    vbMain->addLayout(hb4);
    vbMain->addWidget(EnterBtn);

    SendBtn->setEnabled(false);
}

void TcpClient::slotEnter()
{
    qDebug()<<"enter";
    if( !status )
    {
        QString ip = LineEditServerIp->text();
        if( !ServerIP->setAddress(ip) )
        {
            QMessageBox::information(this,tr("提示"),tr("服务器IP地址有误!"));
            return ;
        }
        if(LineEditUser->text() == "")
        {
            QMessageBox::information(this,tr("提示"),tr("用户名不能为空!"));
            return ;
        }
        UserName = LineEditUser->text();

        tcpSocket = new QTcpSocket;
        connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
        connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

        tcpSocket->connectToHost(*ServerIP,port);
        status = true;
    }else
    {
        int length = 0;
        QString msg = UserName + tr(":leave chat room!");

        if( (length = tcpSocket->write(msg.toLatin1(),msg.length())) != msg.length())
            return ;
        tcpSocket->disconnectFromHost();
        status = false;
        EnterBtn->setText(tr("进入"));
    }
}
void TcpClient::slotConnected()
{
    qDebug()<<"Connected";
    int length = 0;
    SendBtn->setEnabled(true);
    EnterBtn->setText(tr("离开"));

    QString msg = UserName+tr(":enter chat room!");
    if ( (length = tcpSocket->write(msg.toLatin1(), msg.length())) != msg.length())
        return ;
}
void TcpClient::slotDisconnected()
{
    qDebug()<<"Disconnected";
    SendBtn->setEnabled(false);
    SendBtn->setText(tr("进入"));
}
void TcpClient::slotSend()
{
    qDebug()<<"slotSend";
    if(LineEditSend->text() == "")
        return ;
    QString msg = UserName + " : " + LineEditSend->text();

    tcpSocket->write(msg.toLatin1(),msg.length());
    LineEditSend->clear();
}
void TcpClient::dataReceived()
{
    qDebug()<<"dataReceived";
    while(tcpSocket->bytesAvailable() > 0)
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        //QHostAddress sender;

        tcpSocket->read(datagram.data(), datagram.size());

        QString msg = datagram.data();
        ListWidgetContent->addItem(msg.left(datagram.size()));
    }
}
