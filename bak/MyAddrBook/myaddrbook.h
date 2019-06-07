#ifndef MYADDRBOOK_H
#define MYADDRBOOK_H

#include <QtGui>
#include "finddialog.h"

namespace Ui {
    class MyAddrBook;
}

class MyAddrBook : public QWidget
{
    Q_OBJECT

public:
    explicit MyAddrBook(QWidget *parent = 0);
    ~MyAddrBook();
    enum MODE {ADD,EDIT};

private slots:
    void MyAdd();
    void MyEdit();
    void MyRemove();
    void MyFind();
    void MySubmit();
    void MyCancle();
    void MyLoad();
    void MySave();
    void MyExport();
    void MyPrevious();
    void MyNext();

private:
    Ui::MyAddrBook *ui;
    QMap <QString, QString> MyMap;
    QString OldName,OldAddr;
    MODE mode;
    finddialog *dialog;

    void CtrlButton();

};

#endif // MYADDRBOOK_H
