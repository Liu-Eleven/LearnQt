#include "hostinfo.h"

HostInfo::HostInfo( QWidget * parent, Qt::WindowFlags )
    : QWidget(parent)
{
    QLabel *HostName = new QLabel(tr("Host Name:"));
    QLabel *HostIp = new QLabel(tr("Host IP:"));

    //获取机器信息
    //获取机器名字
    QString localHostName = QHostInfo::localHostName();

    QHostInfo hostInfo = QHostInfo::fromName(localHostName);

    QList<QHostAddress> listAddr = hostInfo.addresses();

    HostNameText = new QLineEdit;
    //设置为只读
    HostNameText->setReadOnly(true);
    HostIpText = new QLineEdit;
    HostIpText->setReadOnly(true);
    DetailsBtn = new QPushButton(tr("Details"));
    connect(DetailsBtn,SIGNAL(clicked()),this , SLOT(DetailsInfo()));

    HostNameText->setText(localHostName);

    if( !listAddr.isEmpty() )
        HostIpText->setText(listAddr.first().toString());


    Mainlayout = new QGridLayout;

    Mainlayout->addWidget(HostName,0,0,1,1);
    Mainlayout->addWidget(HostNameText,0,1,1,1);
    Mainlayout->addWidget(HostIp,1,0,1,1);
    Mainlayout->addWidget(HostIpText,1,1,1,1);
    Mainlayout->addWidget(DetailsBtn,2,0,1,2);
    setLayout(Mainlayout);

    resize(200,100);
}

HostInfo::~HostInfo()
{

}

void HostInfo::DetailsInfo()
{
    DetailsHostInfo *DHI = new DetailsHostInfo;
    DHI->show();
    qDebug()<<"lsy";
}

DetailsHostInfo::DetailsHostInfo( QWidget * parent , Qt::WindowFlags  ):
    QWidget(parent)
{
    QString detail;
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    //for(int i=0;i<list.count();i++)
    foreach(QNetworkInterface interface, list)
    {
        //QNetworkInterface interface = list.at(i);
        detail = detail + tr("Device:") + interface.name() + "\n";
        //QString hardwareAddress = interface.hardwareAddress();
        detail = detail + tr("HardwareAddress:") + interface.hardwareAddress() + "\n";
       // qDebug()<<hardwareAddress;

        QList <QNetworkAddressEntry> entryList = interface.addressEntries();

        //for(int j=0;j<entryList.count(); j ++)
        foreach(QNetworkAddressEntry entry , entryList)
        {
            //QNetworkAddressEntry entry = entryList.at(j);

            detail = detail + "\t" + tr("Ip address:") + entry.ip().toString() + "\n";
            detail = detail + "\t" + tr("Netmask :") + entry.netmask().toString() + "\n";
            detail = detail + "\t" + tr("Broadcast:") + entry.broadcast().toString() + "\n";
            break;

        }


    }
    DetailsLabel = new QLabel;
    DetailsLabel->setText(detail);
    QHBoxLayout *MyLayout = new QHBoxLayout;
    MyLayout->addWidget(DetailsLabel);
    setLayout(MyLayout);
    resize(300,300);
}
DetailsHostInfo::~DetailsHostInfo()
{
}
