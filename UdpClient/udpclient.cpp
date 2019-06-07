#include "udpclient.h"

UdpClient::UdpClient(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UDP Client"));

    QVBoxLayout *vbMain = new QVBoxLayout ;

    TextEditReceive = new QTextEdit;
    TextEditReceive->setReadOnly(true);
    PushButtonClose = new QPushButton(tr("Close"));
    connect(PushButtonClose,SIGNAL(clicked()),this,SLOT(close()));

    vbMain->addWidget(TextEditReceive);
    vbMain->addWidget(PushButtonClose);

    udpSocket = new QUdpSocket(this);

    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    port = 6108;
    bool result = udpSocket->bind(port);

    if( !result )
    {
        QMessageBox::information(this,tr("Clue on"),tr("Udp socket create error!"));
        return ;
    }
    setLayout(vbMain);

}

UdpClient::~UdpClient()
{

}

void UdpClient::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg = datagram.data();
        msg = msg + "\n";
        TextEditReceive->insertPlainText(msg);
    }

}
