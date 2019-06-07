#include "mycursor.h"

MyCursor::MyCursor(QWidget *parent)
    : QWidget(parent)
{
    CreateUi();
}

MyCursor::~MyCursor()
{

}

void MyCursor::CreateUi()
{

    label1 = new QPushButton(tr("1"));
    label2 = new QPushButton(tr("2"));
    label3 = new QPushButton(tr("3"));
    label4 = new QPushButton(tr("4"));
    label5 = new QPushButton(tr("5"));
    label6 = new QPushButton(tr("6"));
    label7 = new QPushButton(tr("7"));
    label8 = new QPushButton(tr("8"));
    label9 = new QPushButton(tr("9"));
    label10 = new QPushButton(tr("10"));
    label11 = new QPushButton(tr("11"));
    label12 = new QPushButton(tr("12"));
    label13 = new QPushButton(tr("13"));
    label14 = new QPushButton(tr("14"));
    label15 = new QPushButton(tr("15"));
    label16 = new QPushButton(tr("16"));
    label17 = new QPushButton(tr("17"));
    label18 = new QPushButton(tr("18"));
    label19 = new QPushButton(tr("19"));

    MainLayout = new QGridLayout ;

    MainLayout->addWidget(label1,0,0,1,1);
    MainLayout->addWidget(label2,0,1,1,1);
    MainLayout->addWidget(label3,0,2,1,1);

    MainLayout->addWidget(label4,1,0,1,1);
    MainLayout->addWidget(label5,1,1,1,1);
    MainLayout->addWidget(label6,1,2,1,1);

    MainLayout->addWidget(label7,2,0,1,1);
    MainLayout->addWidget(label8,2,1,1,1);
    MainLayout->addWidget(label9,2,2,1,1);

    MainLayout->addWidget(label10,3,0,1,1);
    MainLayout->addWidget(label11,3,1,1,1);
    MainLayout->addWidget(label12,3,2,1,1);

    MainLayout->addWidget(label13,4,0,1,1);
    MainLayout->addWidget(label14,4,1,1,1);
    MainLayout->addWidget(label15,4,2,1,1);

    MainLayout->addWidget(label16,5,0,1,1);
    MainLayout->addWidget(label17,5,1,1,1);
    MainLayout->addWidget(label18,5,2,1,1);

    MainLayout->addWidget(label19,6,0,1,3);


    connect(label1,SIGNAL(released()),this,SLOT(SetOneCurs()));
    connect(label2,SIGNAL(released()),this,SLOT(SetTwoCurs()));
    connect(label3,SIGNAL(released()),this,SLOT(SetThreeCurs()));
    connect(label4,SIGNAL(released()),this,SLOT(SetFourCurs()));
    connect(label5,SIGNAL(released()),this,SLOT(SetFiveCurs()));
    connect(label6,SIGNAL(released()),this,SLOT(SetSixCurs()));
    connect(label7,SIGNAL(released()),this,SLOT(SetSevenCurs()));
    connect(label8,SIGNAL(released()),this,SLOT(SetEightCurs()));
    connect(label9,SIGNAL(released()),this,SLOT(SetNineCurs()));
    connect(label10,SIGNAL(released()),this,SLOT(SetTenCurs()));
    connect(label11,SIGNAL(released()),this,SLOT(SetElevenCurs()));
    connect(label12,SIGNAL(released()),this,SLOT(SetTwelveCurs()));
    connect(label13,SIGNAL(released()),this,SLOT(SetThirteenCurs()));
    connect(label14,SIGNAL(released()),this,SLOT(SetFourteenCurs()));
    connect(label15,SIGNAL(released()),this,SLOT(SetFifteenCurs()));
    connect(label16,SIGNAL(released()),this,SLOT(SetSixteenCurs()));
    connect(label17,SIGNAL(released()),this,SLOT(SetSeventeenCurs()));
    connect(label18,SIGNAL(released()),this,SLOT(SetEighteenCurs()));
    connect(label19,SIGNAL(released()),this,SLOT(SetNineteenCurs()));

    setLayout(MainLayout);

}

void MyCursor::SetOneCurs()
{

    setCursor(Qt::ArrowCursor);
    qDebug()<<"1";

}

void MyCursor::SetTwoCurs()
{
    setCursor(Qt::UpArrowCursor);
    qDebug()<<"2";
}

void MyCursor::SetThreeCurs()
{
    setCursor(Qt::CrossCursor);
    qDebug()<<"3";
}

void MyCursor::SetFourCurs()
{
    setCursor(Qt::IBeamCursor);
    qDebug()<<"4";
}

void MyCursor::SetFiveCurs()
{
    setCursor(Qt::WaitCursor);
    qDebug()<<"5";
}

void MyCursor::SetSixCurs()
{
    setCursor(Qt::BusyCursor);
    qDebug()<<"6";
}

void MyCursor::SetSevenCurs()
{
    setCursor(Qt::ForbiddenCursor);
    qDebug()<<"7";
}

void MyCursor::SetEightCurs()
{
    setCursor(Qt::PointingHandCursor);
    qDebug()<<"8";
}

void MyCursor::SetNineCurs()
{
    setCursor(Qt::WhatsThisCursor);
    qDebug()<<"9";
}

void MyCursor::SetTenCurs()
{
    setCursor(Qt::SizeVerCursor);
    qDebug()<<"10";
}

void MyCursor::SetElevenCurs()
{
    setCursor(Qt::SizeHorCursor);
    qDebug()<<"11";
}

void MyCursor::SetTwelveCurs()
{
    setCursor(Qt::SizeBDiagCursor);
    qDebug()<<"12";
}

void MyCursor::SetThirteenCurs()
{
    setCursor(Qt::SizeFDiagCursor);
    qDebug()<<"13";
}

void MyCursor::SetFourteenCurs()
{
    setCursor(Qt::SizeAllCursor);
    qDebug()<<"14";
}

void MyCursor::SetFifteenCurs()
{
    setCursor(Qt::SplitVCursor);
    qDebug()<<"15";
}
void MyCursor::SetSixteenCurs()
{
    setCursor(Qt::SplitHCursor);
    qDebug()<<"16";
}

void MyCursor::SetSeventeenCurs()
{
    setCursor(Qt::OpenHandCursor);
    qDebug()<<"17";
}

void MyCursor::SetEighteenCurs()
{
    setCursor(Qt::ClosedHandCursor);
    qDebug()<<"18";
}
void MyCursor::SetNineteenCurs()
{
    QCursor *MyCur = new QCursor(QPixmap("./images/cur.png"),-1,-1);
    setCursor(*MyCur);
    qDebug()<<"19";
}
