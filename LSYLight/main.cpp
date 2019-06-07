#include "mylight.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    //初始化镜头
    scene.setSceneRect(0,0,G_w,G_h*3);
    scene.setBackgroundBrush(Qt::black);

    MyLight *light = new MyLight;

    QState *Red_State = new QState ;
    QState *Yellow_State = new QState ;
    QState *Green_State = new QState ;

    Red_State->assignProperty(light,"color",Qt::red);
    Red_State->assignProperty(light,"pos",QPoint(50,50));

    Yellow_State->assignProperty(light,"color",Qt::yellow);
    Yellow_State->assignProperty(light,"pos",QPoint(50,150));

    Green_State->assignProperty(light,"color",Qt::green);
    Green_State->assignProperty(light,"pos",QPoint(50,250));


    QTimer timer1;
    timer1.setInterval(2000);
    timer1.setSingleShot(true);
    QObject::connect(Red_State,SIGNAL(entered ()),&timer1,SLOT(start()));
    Red_State->addTransition(&timer1, SIGNAL(timeout()), Yellow_State);

    QTimer timer2;
    timer2.setInterval(2000);
    timer2.setSingleShot(true);
    QObject::connect(Yellow_State,SIGNAL(entered ()),&timer2,SLOT(start()));
    Yellow_State->addTransition(&timer2, SIGNAL(timeout()), Green_State);

    QTimer timer3;
    timer3.setInterval(2000);
    timer3.setSingleShot(true);
    QObject::connect(Green_State,SIGNAL(entered()) , &timer3 , SLOT(start()));
    Green_State->addTransition(&timer3, SIGNAL(timeout()) , Red_State);

    QStateMachine machine;
    machine.addState(Red_State);
    machine.addState(Yellow_State);
    machine.addState(Green_State);

    machine.setInitialState(Red_State);
    machine.start();

    //把灯放如镜头
    scene.addItem(light);

/*
//自己的想法，把所有的灯都放如场景中
    MyLight *Red_light = new MyLight;
    QPoint point;
    point.setX(50);
    point.setY(50);
    Red_light->SetPoint(point);
    //light->SetColor(Qt::red);
    scene.addItem(Red_light);

    MyLight *Yellow_light = new MyLight;
    Yellow_light->SetColor(Qt::yellow);
    point.setX(50);
    point.setY(150);
    Yellow_light->SetPoint(point);
    scene.addItem(Yellow_light);

    MyLight *Blue_light = new MyLight;
    Blue_light->SetColor(Qt::blue);
    point.setX(50);
    point.setY(250);
    Blue_light->SetPoint(point);
    scene.addItem(Blue_light);
*/
    //初始化自定义场景，可以更灵活的显示要显示的内容
    MyView view(&scene);

    //设置场景的滚动条,如果用自定义场景，则不需要设置滚动条。
    //view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.resize(G_w , G_h*3);
    view.show();



    QTimer timer;
    QObject::connect(&timer , SIGNAL(timeout()) , &scene , SLOT(update()));
    timer.start(100/33);


    return a.exec();
}
