#include "controlmove.h"

ControlMove::ControlMove(QWidget *parent)
    : QWidget(parent)
{
    image.load("./images/12.jpg");


    startX = 100 ;
    startY = 100 ;

    width =  500;
    height = 400;
    step = 0 ;

    drawPix();
    resize(width,height);
}

ControlMove::~ControlMove()
{

}
//初始化背景
void ControlMove::drawPix()
{
    pix = new QPixmap(width,height);
   // qDebug()<<"[startX = " <<startX << "startY = "<<startY<<"]";
    pix->fill(Qt::white);

    QPainter *Mypainter = new QPainter(pix);

    QPen pen(Qt::DotLine);

    Mypainter->setPen(pen);

   // width =  450;
   // height = 400;
    step = 20 ;

    for(int i = step ; i < width ;)
    {
        //qDebug()<<"i = "<< i << "width "<<width;
        //Mypainter->drawEllipse(100,100,50,50);
        Mypainter->drawLine(QPoint(i,0),QPoint(i,height));
        i = i + step;
    }

    for(int j=step; j<height;)
    {
        //qDebug()<<"Rhz";
        Mypainter->drawLine(QPoint(0,j),QPoint(width,j));
        j = j + step;
    }

    //qDebug()<<"[startX = " <<startX << "startY = ]"<<startY;
    Mypainter->drawImage(QPoint(startX,startY),image);


}

void ControlMove::keyPressEvent(QKeyEvent *event)
{
   // qDebug()<<"qkeyevent...";
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_Left)
        {
            startX = (startX-1 < 0) ? startX : startX-1;
        }

        if(event->key() == Qt::Key_Right)
        {
            startX = (startX+1+image.width() > width) ? startX : startX+1;
        }

        if(event->key() == Qt::Key_Up)
        {
            startY = (startY-1 < 0) ? startY : startY-1;
        }

        if(event->key() == Qt::Key_Down)
        {
            startY = (startY+1+image.height() > height) ? startY : startY+1;
        }

       // qDebug()<<"startX = " <<startX << "startY = "<<startY;
    }else
    {
        startX = startX - startX%step;
        startY = startY - startY%step;

        if(event->key() == Qt::Key_Left)
        {
            startX = (startX - step < 0) ? startX : startX-step;
        }

        if(event->key() == Qt::Key_Right)
        {
            startX = (startX + step + image.width() > width) ? startX : startX + step;
        }

        if(event->key() == Qt::Key_Up)
        {
            startY = (startY - step < 0) ? startY : startY -step;
        }

        if(event->key() == Qt::Key_Down)
        {
            startY = (startY + step + image.height() > height) ? startY : startY + step;

        }

        if(event->key() == Qt::Key_Home)
        {
            startX = 0;
            startY = 0;
        }

        if(event->key() == Qt::Key_End)
        {
            startX = width - image.width();
            startY = height - image.height();
        }

         qDebug()<<"--->startX = " <<startX << "startY = "<<startY;
    }

   // qDebug()<<"(startX = " <<startX << "startY = "<<startY<<")";
    drawPix();
    update();
}

void ControlMove::paintEvent(QPaintEvent *)
{
   // qDebug()<<"paintevent...";
    QPainter painter(this);

    painter.drawPixmap(QPoint(0,0),*pix);
}
