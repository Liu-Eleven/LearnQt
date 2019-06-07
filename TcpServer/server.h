#ifndef SERVER_H
#define SERVER_H

#include "tcpclientsocket.h"
#include <QTcpServer>
#include <QtGui>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0, int port = 0);

    QList <TcpClientSocket *> TcpClientSocketList;

signals:
    void updateServer(QString , int);
public slots:
    void updateClients(QString , int );
    void slotDisconnected(int );

protected:
    void incomingConnection(int socketDescriport);

};

#endif // SERVER_H
