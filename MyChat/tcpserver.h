#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtGui>
#include <QtNetwork>

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = 0);
    ~TcpServer();

private slots:
    void SendMessage();

private:
    QLabel *IpLabel;
    QLabel *PortLabel;

    QPushButton *QuitBtn;

    QGridLayout *MainLayout;

    //提供基于TCP协议的服务
    QTcpServer *Server;

    //字符串列表
    QStringList fortunes;



    void CreateUi();
};

#endif // TCPSERVER_H
