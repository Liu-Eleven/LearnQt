#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QtGui>
#include <QtNetwork>

class MyClient : public QWidget
{
    Q_OBJECT

public:
    MyClient(QWidget *parent = 0);
    ~MyClient();

private slots:
    void GetFortune();
    void ConnectServer();



private:
    QTcpSocket *socket;
    QPushButton *FortuneBtn;
    QPushButton *QuiteBtn;
    QGridLayout *MainLayout ;

    QLabel *ShowMessage;

    QLineEdit *IpText;
    QLineEdit *PortText;
    void CreateUi();
};

#endif // MYCLIENT_H
