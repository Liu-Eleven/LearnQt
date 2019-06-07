#include "drawmouse.h"

MyMouse::MyMouse(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

    timer.setInterval(521);
    color = Qt::yellow;
    connect(&timer,SIGNAL(timeout()),this,SLOT(ChangedColor()));
    timer.start();
}

MyMouse::~MyMouse()
{

}


void MyMouse::paint ( QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget = 0*/ )
{

    //qDebug()<<ReadTurn();
       painter->rotate(ReadTurn());
    // Body
       painter->setBrush(color);
       painter->drawEllipse(-10, -20, 20, 40);

       // Eyes
       painter->setBrush(Qt::white);
       painter->drawEllipse(-10, -17, 8, 8);
       painter->drawEllipse(2, -17, 8, 8);

       // Nose
       painter->setBrush(Qt::black);
       painter->drawEllipse(QRectF(-2, -22, 4, 4));

       //mustache
       painter->setBrush(Qt::black);
       painter->drawLine(-2,-22,-6,-22);
       painter->drawLine(-2,-22,6,-22);

       // Pupils
       painter->drawEllipse(QRectF(-8.0 + mouseEyeDirection, -17, 4, 4));
       painter->drawEllipse(QRectF(4.0 + mouseEyeDirection, -17, 4, 4));

       // Ears
       painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
       painter->drawEllipse(-17, -12, 16, 16);
       painter->drawEllipse(1, -12, 16, 16);

       // Tail
       QPainterPath path(QPointF(0, 20));
       path.cubicTo(-5, 22, -5, 22, 0, 25);
       path.cubicTo(5, 27, 5, 32, 0, 30);
       path.cubicTo(-5, 32, -5, 42, 0, 35);
       painter->setBrush(Qt::NoBrush);
       painter->drawPath(path);

}
QRectF MyMouse::boundingRect () const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                   36 + adjust, 60 + adjust);
}

void MyMouse::ChangedColor()
{
    color= QColor(qrand()%255,qrand()%255,qrand()%255);
}
