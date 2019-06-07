#include "mylight.h"

MyLight::MyLight(QGraphicsItem *parent)
    : QGraphicsObject(parent),m_color(Qt::red)
{
}

MyLight::~MyLight()
{

}

void MyLight::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   // QBrush brush;
   // brush.setColor(m_color);
    painter->setBrush(m_color);
   /* QPoint point;
    point.setX(50);
    point.setY(50);*/
    painter->drawEllipse(m_point,G_r,G_r);
    //painter->drawLine(20,20,60,60);
}
QRectF MyLight::boundingRect() const
{
    return QRectF(0,0,G_r,G_r);
}

MyView::MyView( QGraphicsScene * scene, QWidget * parent):
    QGraphicsView(scene,parent)
{

}

MyView::~MyView()
{

}
void MyView::resizeEvent ( QResizeEvent * )
{
    fitInView(scene()->sceneRect());

   // QGraphicsView::resizeEvent(event);
}
