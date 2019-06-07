#include <QtGui>
#include "drawmouse.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *Scene = new QGraphicsScene;
    Scene->setSceneRect(0,0,300,300);
    //Scene->addPixmap(QPixmap("./images/Backdrop.png"));
    Scene->setBackgroundBrush(QPixmap("./images/Backdrop1.png"));


    MyMouse mouse;
    //把物品放如镜头
    Scene->addItem(&mouse);

    //添加一个状态
    //老鼠跑的第一阶段
    QState *state1 = new QState;
    state1->assignProperty(&mouse,"turn",90);
    state1->assignProperty(&mouse,"pos",QPointF(38,18));

    QState *state2 = new QState;
    state2->assignProperty(&mouse,"turn",90);
    state2->assignProperty(&mouse,"pos",QPointF(300-22,18));

    QState *state3 = new QState ;
    state3->assignProperty(&mouse,"turn",180);
    state3->assignProperty(&mouse,"pos",QPointF(300-22,300-22));

    QState *state4 = new QState ;
    state4->assignProperty(&mouse,"turn",270);
    state4->assignProperty(&mouse,"pos",QPointF(18,300-22));

    QState *state5 = new QState;
    state5->assignProperty(&mouse, "turn" ,360);
    state5->assignProperty(&mouse, "pos", QPointF(18,22));

//给老鼠添加动画
    QTimer timer1;
    timer1.setInterval(521);
    timer1.setSingleShot(true);
    //timer1.start();
    QObject::connect(state1,SIGNAL(entered ()),&timer1,SLOT(start()));
    QSignalTransition *tran1 = state1->addTransition(&timer1 , SIGNAL(timeout()) , state2);//添加一个信号
    QPropertyAnimation ani1(&mouse,"pos");//添加一个动画
    ani1.setDuration(2000);
    tran1->addAnimation(&ani1);//把动画放到信号里

    QTimer timer2;
    timer2.setInterval(2000);
    timer2.setSingleShot(true);
    QObject::connect(state2,SIGNAL(entered ()),&timer2,SLOT(start()));
    QSignalTransition *tran2 = state2->addTransition(&timer2 , SIGNAL(timeout()) , state3);
    QPropertyAnimation ani2(&mouse,"pos");
    ani2.setDuration(2000);
    tran2->addAnimation(&ani2);

    QTimer timer3;
    timer3.setInterval(2000);
    timer3.setSingleShot(true);
    QObject::connect(state3,SIGNAL(entered ()),&timer3,SLOT(start()));
    QSignalTransition *tran3 = state3->addTransition(&timer3, SIGNAL(timeout()), state4);
    QPropertyAnimation ani3(&mouse,"pos");
    ani3.setDuration(2000);
    tran3->addAnimation(&ani3);

    QTimer timer4;
    timer4.setInterval(2000);
    timer4.setSingleShot(true);
    QObject::connect(state4,SIGNAL(entered ()),&timer4,SLOT(start()));
    QSignalTransition *tran4 = state4->addTransition(&timer4, SIGNAL(timeout()), state5);
    QPropertyAnimation ani4(&mouse,"pos");
    ani4.setDuration(2000);
    tran4->addAnimation(&ani4);


//添加一个管理机制
    QStateMachine machine;

    machine.addState(state1);
    machine.addState(state2);

    machine.addState(state3);
    machine.addState(state4);

    machine.addState(state5);

    machine.setInitialState(state1);
    machine.start();


    QGraphicsView view(Scene);
    view.show();

    QTimer timer;
    QObject::connect(&timer , SIGNAL(timeout()) , Scene , SLOT(update()));
    timer.start(1000/33);

    return a.exec();
}

