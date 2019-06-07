#include "tcpserver.h"

TcpServer::TcpServer(QWidget *parent)
    : QDialog(parent)
{

    setWindowTitle(tr("Tcp Server"));

    ListWidgetContent = new QListWidget;
    LabelPort = new QLabel(tr("端口号:"));
    LineEditPort = new QLineEdit;
    CreateClientBtn = new QPushButton(tr("创建聊天室"));
    connect(CreateClientBtn,SIGNAL(clicked()),this,SLOT(CreateServer()));

    QHBoxLayout *hb = new QHBoxLayout ;
    hb->addWidget(LabelPort);
    hb->addWidget(LineEditPort);

    QVBoxLayout *vbMain = new QVBoxLayout ;
    vbMain->addWidget(ListWidgetContent);
    vbMain->addLayout(hb);
    vbMain->addWidget(CreateClientBtn);

    setLayout(vbMain);

    port = 6108;
    LineEditPort->setText(QString::number(port));

}

TcpServer::~TcpServer()
{

}

void TcpServer::CreateServer()
{
    qDebug()<<"create";
    QString msg = tr("聊天室已创建成功!");
    ListWidgetContent->addItem(msg.left(msg.length()));
    server = new Server(this , port);
    connect(server,SIGNAL(updateServer(QString,int)),this ,SLOT(UpadteServer(QString,int)));

}
void TcpServer::UpadteServer(QString msg, int length)
{
    qDebug()<<"update";
    ListWidgetContent->addItem(msg.left(length));
}
