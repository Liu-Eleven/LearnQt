#ifndef MSGBOX_H
#define MSGBOX_H

#include <QtGui>

class MsgBox : public QWidget
{
    Q_OBJECT

public:
    MsgBox(QWidget *parent = 0);
    ~MsgBox();
private slots:
    void Slot_Question();
    void Slot_Warning();
    void Slot_About();
    void Slot_Custom();
    void Slot_Information();
    void Slot_Critical();

private:
    QLabel *L_title;
    QPushButton *Btn_Question;//询问
    QPushButton *Btn_Warning;//警告
    QPushButton *Btn_About;//关于
    QPushButton *Btn_Custom;//自定义
    QPushButton *Btn_Information;//信息
    QPushButton *Btn_Critical;//判断

    QGridLayout *MainLayout;

    void CreateMsgBoxUi();
};

#endif // MSGBOX_H
