#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtGui>
#include <QtNetwork>
#include "server.h"

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = 0);
    ~TcpServer();

private slots:
    void CreateServer();
    void UpadteServer(QString , int);

private:
    QListWidget *ListWidgetContent;
    QLabel *LabelPort;
    QLineEdit *LineEditPort;
    QPushButton *CreateClientBtn;

    int port ;
    Server *server;
};

#endif // TCPSERVER_H
