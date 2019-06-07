#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QtNetwork>


class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = 0);

signals:
    void updateClients(QString , int );
    void disconnected(int );
protected slots:
    void dataReceived();
    void slotDisconnected();

};

#endif // TCPCLIENTSOCKET_H
