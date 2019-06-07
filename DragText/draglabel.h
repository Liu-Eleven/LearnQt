#ifndef DRAGLABEL_H
#define DRAGLABEL_H

#include <QtGui>

class DragLabel : public QLabel
{
    Q_OBJECT
public:
    DragLabel ( const QString &text , QWidget * parent = 0);
    ~DragLabel();
protected :
    void mousePressEvent(QMouseEvent *ev);
};

#endif // DRAGLABEL_H
