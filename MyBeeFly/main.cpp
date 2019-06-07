#include <QtGui/QApplication>
#include "Beelfly.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0,0,400,400);//QRectF(-200,-200,400,400)
    scene->setBackgroundBrush(QPixmap("./images/back.PNG"));


  /*  Beelfly *b = new Beelfly;
    b->setPos(0,50);
    Beelfly *b1 = new Beelfly;
    b1->setPos(0,100);
    Beelfly *b2 = new Beelfly;
    b2->setPos(0,150);*/
    Beelfly *b3 = new Beelfly;
    b3->setPos(100,200);
  /*  Beelfly *b4 = new Beelfly;
    b4->setPos(0,250);
    Beelfly *b5 = new Beelfly;
    b5->setPos(0,250);
    Beelfly *b6 = new Beelfly;
    b6->setPos(0,300);
    Beelfly *b7 = new Beelfly;
    b7->setPos(0,350);*/



   // scene->addItem(b);
   // scene->addItem(b1);
   // scene->addItem(b2);
    scene->addItem(b3);
   // scene->addItem(b4);
   // scene->addItem(b5);
   // scene->addItem(b6);
   // scene->addItem(b7);




    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->resize(400,400);
    view->show();
/*
    QTimer timer;
    QObject::connect(&timer,SIGNAL(timeout()),scene,SLOT(update()));
    timer.start(1000/33);*/

    return a.exec();
}
