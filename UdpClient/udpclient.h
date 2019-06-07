#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QtGui>
#include <QtNetwork>
class UdpClient : public QDialog
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = 0);
    ~UdpClient();

private slots:
    void dataReceived();

private:
    QTextEdit *TextEditReceive ;
    QPushButton *PushButtonClose;

    QUdpSocket *udpSocket;

    int port ;

};

#endif // UDPCLIENT_H
