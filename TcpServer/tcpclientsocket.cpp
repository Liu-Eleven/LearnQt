#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent) :
    QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

void TcpClientSocket::dataReceived()
{
    //bytesAvailable :Returns the number of bytes that are waiting to be written, i.e. the size of the output buffer.
    while( bytesAvailable() > 0)
    {
        char buf[1024];

        int length = bytesAvailable();

        read(buf,length);
        QString msg = buf;
        emit updateClients(msg,length);
    }
}

void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}

