#include "mouseevent.h"

MouseEvent::MouseEvent(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Get Mouse Event"));

    LabelState = new QLabel;
    LabelState->setText(tr("Mouse Position:"));
    LabelState->setFixedWidth(80);

    LabelMousePos = new QLabel;
    LabelMousePos->setText(tr("123"));
    LabelMousePos->setFixedWidth(80);

    statusBar()->addPermanentWidget(LabelState);
    statusBar()->addPermanentWidget(LabelMousePos);

    this->setMouseTracking(true);
    resize(500,450);
}

MouseEvent::~MouseEvent()
{

}


void MouseEvent::mouseMoveEvent(QMouseEvent *e)
{
    //qDebug()<<"mouse move event....";
    LabelMousePos->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
}

void MouseEvent::mousePressEvent(QMouseEvent *e)
{
    //qDebug()<<"mouse Press Event....";
   // qDebug()<<"global x = "<<e->globalX();//globalX()可以得到鼠标相对于屏幕的位置
    QString str = "("+QString::number(e->x())+","+QString::number(e->y())+")";

    if(e->button() == Qt::LeftButton)
    {
        statusBar()->showMessage(tr("Mouse Left Button Pressed!")+str);
    }else if(e->button() == Qt::RightButton)
    {
        statusBar()->showMessage(tr("Mouse Right Button Pressed!")+str);
    }else if(e->button() == Qt::MidButton)
    {
        statusBar()->showMessage(tr("Mouse middle Button Pressed!")+str);
    }
}

void MouseEvent::mouseReleaseEvent(QMouseEvent *e)
{
    //qDebug()<<"mouse Release Event....";
    QString str = "("+QString::number(e->x())+","+QString::number(e->y())+")";
    statusBar()->showMessage(tr("Mouse Released!")+str,300);
}
void MouseEvent::mouseDoubleClickEvent(QMouseEvent *e)
{
    QString str = "("+QString::number(e->x())+","+QString::number(e->y())+")";
    statusBar()->showMessage(tr("Mouse DoubleClick!")+str,300);
    sleep(1);
}
