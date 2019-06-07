#include "myclient.h"

MyClient::MyClient(QWidget *parent)
    : QWidget(parent)
{
    CreateUi();
    resize(250,100);
}

MyClient::~MyClient()
{

}

void MyClient::CreateUi()
{
    socket = new QTcpSocket(this);
    //void QIODevice::readyRead () [signal]
    //每当新数据可以从设备中获取时， socket发出信号readyRead()
    connect(socket,SIGNAL(readyRead()),this,SLOT(GetFortune()));

    FortuneBtn = new QPushButton(tr("Get Fortune"));
    //单击此按钮，链接服务器
    connect(FortuneBtn,SIGNAL(clicked()),this,SLOT(ConnectServer()));

    QuiteBtn = new QPushButton(tr("Quite"));
    connect(QuiteBtn,SIGNAL(clicked()),this,SLOT(close()));

    QLabel *IpLabel = new QLabel(tr("IP:"));
    IpText =new QLineEdit;
    //设置为只读
    IpText->setReadOnly(true);

    QLabel *PortLabel = new QLabel(tr("Port:"));
    PortText = new QLineEdit;
    //设置段口号的最大和最小数值
    PortText->setValidator(new QIntValidator(1,99999,this));

    ShowMessage = new QLabel(tr("No connect!"));

    QString strAddr;
    QList<QHostAddress> AddrList = QNetworkInterface::allAddresses();

    foreach(QHostAddress addr , AddrList)
    {
        if(addr != QHostAddress::LocalHost && addr.toIPv4Address())
            strAddr = addr.toString();
    }
    //设置IP地址
    IpText->setText(strAddr);

    //布局管理器
    MainLayout = new QGridLayout ;

    MainLayout->addWidget(IpLabel,0,0,1,1);
    MainLayout->addWidget(IpText,0,1,1,1);
    MainLayout->addWidget(PortLabel,1,0,1,1);
    MainLayout->addWidget(PortText,1,1,1,1);
    MainLayout->addWidget(ShowMessage,2,0,1,2);
    MainLayout->addWidget(FortuneBtn,3,0,1,1);
    MainLayout->addWidget(QuiteBtn,3,1,1,1);

    setLayout(MainLayout);


}

void MyClient::GetFortune()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);

    QString NextData;
    in >> NextData;

    ShowMessage->setText(NextData);
    FortuneBtn->setEnabled(true);

}


void MyClient::ConnectServer()
{
    FortuneBtn->setEnabled(false);
    //void QAbstractSocket::abort ()
    //放弃当前的链接， 重置socket； 该函数会立即关闭socket， 放弃所有在write buffer中的数据
    socket->abort();

    QHostAddress address(IpText->text());

    //void QAbstractSocket::connectToHost ( const QString & hostName, quint16 port, OpenMode openMode = ReadWrite )
    //试图从给定的端口port上连接到主机hostname;
    //socket的状态变化是：先进入状态HostLookupState， 找到主机， 发出信号hostFound(),
    //然后进入状态ConnectingState。最后连接建立起来， 进入状态ConnectedState, 发出信号connected()

    socket->connectToHost(address,PortText->text().toInt());
}
