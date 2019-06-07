#include "udpserver.h"

UdpServer::UdpServer(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UDP Server"));



    LabelTimer = new QLabel(tr("Timer:"));
    LineEditText = new QLineEdit;
    PushButtonStart = new QPushButton(tr("Start"));
    connect(PushButtonStart, SIGNAL(clicked()),this,SLOT(clickedIsStart()));

    QVBoxLayout *vbMain = new QVBoxLayout;
    vbMain->addWidget(LabelTimer);
    vbMain->addWidget(LineEditText);
    vbMain->addWidget(PushButtonStart);

    port = 6108;
    isStarted = false;
    udpSocket = new QUdpSocket(this);

    timer = new QTimer(this);
    timer->setInterval(1000);
   // timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this , SLOT(Mytimeout()));

    setLayout(vbMain);
}

UdpServer::~UdpServer()
{

}
/*
void UdpServer::ChangedButton()
{
    qDebug()<<"LSY";
      QState *Off = new QState ;
      Off->assignProperty(PushButtonStart,"text",tr("Off"));

      QState *On = new QState ;
      On->assignProperty(PushButtonStart,"text",tr("On"));


      //提供一个层次化的有限状态机
      QStateMachine Btn_Machine;
      //在状态机中添加状态
      Btn_Machine.addState(Off);
      Btn_Machine.addState(On);
      //设置状态机的初始状态
      Btn_Machine.setInitialState(Off);
      //启动状态机制
      Btn_Machine.start();

      //给按钮添加事件
      Off->addTransition(PushButtonStart,SIGNAL(clicked()),On);
      On->addTransition(PushButtonStart,SIGNAL(clicked()),Off);

}
*/
void UdpServer::clickedIsStart()
{

    qDebug()<<isStarted;
    if (isStarted == false)
    {
        qDebug()<<"true";
        isStarted = true;
        timer->setSingleShot(false);
        PushButtonStart->setText(tr("ON"));
        timer->start();
        return ;
    }

    if ( isStarted == true)
    {
        qDebug()<<"false";
        PushButtonStart->setText(tr("OFF"));
        timer->setSingleShot(true);
        isStarted = false;
    }
}
void UdpServer::Mytimeout()
{
    QString msg = LineEditText->text();
    int length = 0;
    if(msg == "")
        return ;
    if( (length = udpSocket->writeDatagram(
                msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port)) !=msg.length())
    {
        return ;
    }
}
