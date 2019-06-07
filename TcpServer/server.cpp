#include "server.h"

Server::Server(QObject *parent,int port) :
    QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

void Server::incomingConnection(int socketDescriport)
{
    TcpClientSocket *tcpclientsocket = new TcpClientSocket(this);

    connect(tcpclientsocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));
    connect(tcpclientsocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));
    tcpclientsocket->setSocketDescriptor(socketDescriport);
    TcpClientSocketList.append(tcpclientsocket);
}

void Server::updateClients(QString msg, int length)
{
    emit updateServer(msg , length);

    for(int i=0; i < TcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = TcpClientSocketList.at(i);

        if(  item->write(msg.toLatin1(),length) != length )
        {
            continue;
        }
    }

}
void Server::slotDisconnected(int descriport)
{

    for(int i=0; i < TcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = TcpClientSocketList.at(i);

        if( item->socketDescriptor() == descriport )
        {
            TcpClientSocketList.removeAt(i);
            return ;
        }
    }
    return ;
}

