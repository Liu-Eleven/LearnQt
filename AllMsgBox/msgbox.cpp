#include "msgbox.h"

MsgBox::MsgBox(QWidget *parent)
    : QWidget(parent)
{
    CreateMsgBoxUi();
}

MsgBox::~MsgBox()
{

}

void MsgBox::CreateMsgBoxUi()
{
    L_title = new QLabel(tr("This is MessageBox example:"));
    Btn_Question = new QPushButton(tr("Question"));//询问
    Btn_Warning = new QPushButton(tr("Warning"));//警告
    Btn_About = new QPushButton(tr("About"));//关于
    Btn_Custom = new QPushButton(tr("Custom"));//自定义
    Btn_Information = new QPushButton(tr("Information"));//信息
    Btn_Critical = new QPushButton(tr("Critical"));//判断

    MainLayout = new QGridLayout ;

    MainLayout->addWidget(L_title,0,0,1,2);

    MainLayout->addWidget(Btn_Question,1,0,1,1);
    MainLayout->addWidget(Btn_Warning,1,1,1,1);
    MainLayout->addWidget(Btn_About,1,2,1,1);

    MainLayout->addWidget(Btn_Custom,2,0,1,1);
    MainLayout->addWidget(Btn_Information,2,1,1,1);
    MainLayout->addWidget(Btn_Critical,2,2,1,1);

    //添加信号槽机制
    connect(Btn_Question,SIGNAL(clicked()),this,SLOT(Slot_Question()));
    connect(Btn_Warning,SIGNAL(clicked()),this,SLOT(Slot_Warning()));
    connect(Btn_About,SIGNAL(clicked()),this,SLOT(Slot_About()));
    connect(Btn_Custom,SIGNAL(clicked()),this,SLOT(Slot_Custom()));
    connect(Btn_Information,SIGNAL(clicked()),this,SLOT(Slot_Information()));
    connect(Btn_Critical,SIGNAL(clicked()),this,SLOT(Slot_Critical()));

    setLayout(MainLayout);
}
//弹出询问对话框
void MsgBox::Slot_Question()
{
   // qDebug()<<"QUestion..";
    int ret = QMessageBox::question(this,tr("Question message"),
                                    tr("This is a Question messagebox?"),
                                    QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::Discard,
                                    QMessageBox::Ok);
    switch(ret)
    {
    case QMessageBox::Ok:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [Ok key]!"));
        break;
    case QMessageBox::Cancel:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [Cancel key]!"));
        break;
    case QMessageBox::Discard:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [Discard key]!"));
        break;
    default:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [ error ]!"));
    }
}
//弹出警告对话框
void MsgBox::Slot_Warning()
{
    //qDebug()<<"Warning..";
    int ret = QMessageBox::warning(this,tr("Warning message"),
                                   tr("This is a warning messagebox!"),
                                   QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::Discard,
                                   QMessageBox::Cancel);
    switch(ret)
    {
    case QMessageBox::Ok:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [Ok key]!"));
        break;
    case QMessageBox::Cancel:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [Cancel key]!"));
        break;
    case QMessageBox::Discard:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [Discard key]!"));
        break;
    default:
        QMessageBox::about(this,tr("Clue on"),tr("Your choose [ error ]!"));
    }

}
//关于消息对话框
void MsgBox::Slot_About()
{
   // qDebug()<<"About..";
    QMessageBox::about(this,tr("Clue on"),tr("This is a about messagebox!"));
}
//自定义消息框
void MsgBox::Slot_Custom()
{
    //qDebug()<<"Custom..";
    QMessageBox CustomMsg(this);
    CustomMsg.setWindowTitle("Custom message box");

    QAbstractButton  *lockButton = CustomMsg.addButton(tr("Lock"),
                                                  QMessageBox::ActionRole);

    QAbstractButton  *UnlockButton = CustomMsg.addButton(tr("Unlock"),
                                                    QMessageBox::ActionRole);

    QAbstractButton  *CancelButton = CustomMsg.addButton(QMessageBox::Cancel);

    CustomMsg.setIconPixmap(QPixmap("./images/def.png"));
    CustomMsg.setText(tr("This is user custom messagebox!"));

    CustomMsg.exec();


    if(CustomMsg.clickedButton() == lockButton)
    {
        QMessageBox::about(this,tr("Clue on"),tr("Your choose lock QQ!"));
    }else if(CustomMsg.clickedButton() == UnlockButton)
    {
        QMessageBox::about(this,tr("Clue on"),tr("Your choose Unlock QQ!"));
    }else if(CustomMsg.clickedButton() == CancelButton)
    {
        QMessageBox::about(this,tr("Clue on"),tr("Your choose Cancel logo QQ!"));
    }

}
void MsgBox::Slot_Information()
{
    //qDebug()<<"Information..";
    QMessageBox::information(this,tr("Information message"),
                             tr("This is a information messagebox"),
                             QMessageBox::Ok);
}
//弹出严重错误对话框
void MsgBox::Slot_Critical()
{
    qDebug()<<"Critical..";
    QMessageBox::critical(this,tr("Critical message"),
                          tr("This is a Critical messagebox!"),
                          QMessageBox::Ok | QMessageBox::Cancel,
                          QMessageBox::Ok);
}
