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
    painter->setBrush(m_color);
    painter->drawEllipse(m_point,G_r,G_r);
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
void MyView::resizeEvent ( QResizeEvent *event )
{
    fitInView(scene()->sceneRect());

    QGraphicsView::resizeEvent(event);
}
