#include "Beelfly.h"

static const double Pi = 3.141592653;

Beelfly::Beelfly(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    pix_up.load("./images/Butterfly.ico");
    pix_down.load("./images/Butterfly.ico");


    timer.setInterval(1000);
    connect(&timer , SIGNAL(timeout()) , this , SLOT(ChangedTurn()));
    timer.start();

    up = true;
    startTimer(100);
}

Beelfly::~Beelfly()
{

}

void Beelfly::paint(QPainter *painter , const QStyleOptionGraphicsItem */*option*/ , QWidget */*widget*/)
{
    painter->rotate(m_turn);
    painter->drawPixmap(boundingRect().topLeft(), pix_down);
   /* if(up)
    {
        painter->drawPixmap(boundingRect().topLeft(), pix_up);
        up = false;
    }else
    {
       painter->drawPixmap(boundingRect().topLeft(), pix_down);
        up = true;
    }*/
}

void Beelfly::timerEvent(QTimerEvent *)
{
    //边界控制
    qreal edgex = scene()->sceneRect().right() - boundingRect().width()/2;

    qreal edgetop = scene()->sceneRect().top() - boundingRect().height()/2;

    qreal edgebottom = scene()->sceneRect().bottom() - boundingRect().height()/2;



    if(pos().x() >= edgex )
        setPos(scene()->sceneRect().left(),pos().y());
    if(pos().y() <= edgetop)
        setPos(pos().x(), scene()->sceneRect().bottom());

    if(pos().y() >= edgebottom )
        setPos(pos().x() , scene()->sceneRect().top());

    angle += (qrand()%10)/20.0;
    qreal dx = fabs(sin(angle*Pi)*10.0);
    qreal dy = (qrand()%20)-10.0;

    setPos(mapToParent(dx,dy));//改变坐标

}

QRectF Beelfly::boundingRect() const
{
    qreal adjust = 2;
    //以蜜蜂本身为整体，返回一个整体
    return QRectF(-pix_up.width()/2-adjust, -pix_up.height()/2-adjust,
                  pix_up.width()+adjust*2, pix_up.height()+2*adjust);
}

void Beelfly::ChangedTurn()
{
    m_turn = qrand()%360;

}
