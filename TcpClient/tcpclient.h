#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtGui>
#include <QtNetwork>

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = 0);
    ~TcpClient();

private slots:
    void slotEnter();
    void slotConnected();
    void slotDisconnected();
    void slotSend();
    void dataReceived();
private:
    QListWidget *ListWidgetContent;
    QLineEdit *LineEditSend;
    QPushButton *SendBtn;
    QLabel *labelUser;
    QLineEdit *LineEditUser;
    QLabel *labelServerIP;
    QLineEdit *LineEditServerIp;
    QLabel *LabelPort;
    QLineEdit *LineEditPort;
    QPushButton * EnterBtn;

    QString UserName;
    int port ;
    QHostAddress *ServerIP;
    QTcpSocket *tcpSocket;
    bool status;

    void CreateUi();

};

#endif // TCPCLIENT_H
