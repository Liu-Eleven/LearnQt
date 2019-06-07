#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QtGui>
#include <QtNetwork>

class UdpServer : public QDialog
{
    Q_OBJECT

public:
    UdpServer(QWidget *parent = 0);
    ~UdpServer();

private slots:
    void Mytimeout();
    void clickedIsStart();
private:
    QLabel *LabelTimer;
    QLineEdit *LineEditText;

    QPushButton *PushButtonStart;

    int port ;
    bool isStarted ;
    QUdpSocket *udpSocket;
    QTimer *timer;


};

#endif // UDPSERVER_H
