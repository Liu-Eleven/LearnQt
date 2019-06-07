#ifndef MYDRAGDROP_H
#define MYDRAGDROP_H

#include <QtGui>

class Mydragdrop : public QFrame
{
    Q_OBJECT

public:
    Mydragdrop( QWidget * parent = 0);
    ~Mydragdrop();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);

};

#endif // MYDRAGDROP_H
