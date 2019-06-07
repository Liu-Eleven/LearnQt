#include "myblock.h"

MyBlock::MyBlock(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
       timer.setInterval(1000);
       connect(&timer,SIGNAL(timeout()),this,SLOT(ChangeColor()));
       timer.start();
       //color = Qt::blue;
}
/*
MyBlock::MyBlock(QColor color,QGraphicsItem *parent)
    : QGraphicsObject(parent),color(color)
{
       timer.setInterval(1000);
       connect(&timer,SIGNAL(timeout()),this,SLOT(ChangeColor()))
}
*/

MyBlock::~MyBlock()
{

}

void MyBlock::paint ( QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget = 0*/ )
{
    /*QRectF rect(0,0,50,50);
    painter->fillRect(rect,Qt::blue);*/

    painter->setBrush(color);
    painter->drawEllipse(0,0,50,50);
}
QRectF MyBlock::boundingRect () const
{
    return QRectF(0,0,61,61);
}

void MyBlock::ChangeColor()
{
    color= QColor(qrand()%255,qrand()%255,qrand()%255);
    //qDebug()<<"lsy";

}
