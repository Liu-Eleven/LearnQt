#ifndef DRAGWORD_H
#define DRAGWORD_H

#include <QtGui>
#include "draglabel.h"

class DragWord : public QFrame
{
    Q_OBJECT

public:
    DragWord (QWidget * parent = 0 );
    ~DragWord();
protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);
};

#endif // DRAGWORD_H
