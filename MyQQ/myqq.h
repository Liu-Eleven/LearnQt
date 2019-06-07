#ifndef MYQQ_H
#define MYQQ_H

#include <QtGui>

class MyQQ : public QToolBox
{
    Q_OBJECT

public:
    MyQQ( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    ~MyQQ();

private:
    QToolButton *toolBtn1_1;
    QToolButton *toolBtn1_2;
    QToolButton *toolBtn1_3;
    QToolButton *toolBtn1_4;
    QToolButton *toolBtn1_5;

    QToolButton *toolBtn2_1;
    QToolButton *toolBtn2_2;

    QToolButton *toolBtn3_1;
    QToolButton *toolBtn3_2;
};

#endif // MYQQ_H
