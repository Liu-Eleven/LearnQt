#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QtGui>

class MouseEvent : public QMainWindow
{
    Q_OBJECT

public:
    MouseEvent(QWidget *parent = 0);
    ~MouseEvent();

protected :
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

private :
    QLabel *LabelState;
    QLabel *LabelMousePos;
};

#endif // MOUSEEVENT_H
