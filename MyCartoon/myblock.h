#ifndef MYBLOCK_H
#define MYBLOCK_H

#include <QtGui>

class MyBlock : public QGraphicsObject
{
    Q_OBJECT

public:
    MyBlock (QGraphicsItem * parent = 0 );
    //QColor color = Qt::yellow,
    ~MyBlock();

    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    QRectF boundingRect () const;

private slots:
    void ChangeColor();

private :
        QColor color ;
        QTimer timer;
};

#endif // MYBLOCK_H
