#ifndef DRAGTEXT_H
#define DRAGTEXT_H

#include <QtGui>

class DragText : public QWidget
{
    Q_OBJECT

public:
    DragText(QWidget *parent = 0);
    ~DragText();
protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);
    void mousePressEvent(QMouseEvent *);
};

#endif // DRAGTEXT_H
