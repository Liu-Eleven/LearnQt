#include "mylight.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene scene;
    //初始化镜头
    scene.setSceneRect(0,0,G_w,G_h*3);
    scene.setBackgroundBrush(Qt::black);

    MyLight *light = new MyLight;

    //红色闪烁状态
    QState *RedCoruscate = new QState;
    //红色状态
    QState *RedState = new QState;
    //红色闪烁状态子状态
    QState *Red_State = new QState(RedCoruscate) ;
    QState *RedCloseState = new QState(RedCoruscate);

    RedState->assignProperty(light,"color",Qt::red);
    RedState->assignProperty(light,"pos",QPoint(50,50));

    Red_State->assignProperty(light,"color",Qt::red);
    Red_State->assignProperty(light,"pos",QPoint(50,50));
    RedCloseState->assignProperty(light,"color",Qt::black);
    RedCloseState->assignProperty(light,"pos",QPoint(50,50));

    //黄色闪烁状态(返回状态)
    QState *YellowCoruscate1 = new QState;
    //黄色状态
    QState *YellowState1 = new QState;
    //黄色闪烁状态子状态
    QState *Yellow_State1 = new QState(YellowCoruscate1) ;
    QState *YellowCloseState1 = new QState(YellowCoruscate1);

    YellowState1->assignProperty(light,"color",Qt::yellow);
    YellowState1->assignProperty(light,"pos",QPoint(50,150));

    Yellow_State1->assignProperty(light,"color",Qt::yellow);
    Yellow_State1->assignProperty(light,"pos",QPoint(50,150));
    YellowCloseState1->assignProperty(light,"color",Qt::black);
    YellowCloseState1->assignProperty(light,"pos",QPoint(50,150));

    //黄色闪烁状态
    QState *YellowCoruscate = new QState;
    //黄色状态
    QState *YellowState = new QState;
    //黄色闪烁状态子状态
    QState *Yellow_State = new QState(YellowCoruscate) ;
    QState *YellowCloseState = new QState(YellowCoruscate);

    YellowState->assignProperty(light,"color",Qt::yellow);
    YellowState->assignProperty(light,"pos",QPoint(50,150));

    Yellow_State->assignProperty(light,"color",Qt::yellow);
    Yellow_State->assignProperty(light,"pos",QPoint(50,150));
    YellowCloseState->assignProperty(light,"color",Qt::black);
    YellowCloseState->assignProperty(light,"pos",QPoint(50,150));

    //绿色闪烁状态
    QState *GreenCoruscate = new QState;
    //绿色状态
    QState *GreenState = new QState;
    //绿色闪烁状态子状态
    QState *Green_State = new QState(GreenCoruscate);
    QState *GreenCloseState = new QState(GreenCoruscate);

    GreenState->assignProperty(light,"color",Qt::green);
    GreenState->assignProperty(light,"pos",QPoint(50,250));

    Green_State->assignProperty(light,"color",Qt::green);
    Green_State->assignProperty(light,"pos",QPoint(50,250));
    GreenCloseState->assignProperty(light,"color",Qt::black);
    GreenCloseState->assignProperty(light,"pos",QPoint(50,250));

    //设置每个灯状态的默认子状态
    RedCoruscate->setInitialState(Red_State);
    YellowCoruscate->setInitialState(Yellow_State);
    YellowCoruscate1->setInitialState(Yellow_State1);
    GreenCoruscate->setInitialState(Green_State);


    QTimer timer1,timer2;
    timer1.setInterval(521);
    timer1.setSingleShot(true);

    timer2.setInterval(3331);
    timer2.setSingleShot(true);

    //红灯闪烁
    QObject::connect(Red_State,SIGNAL(entered()),&timer1,SLOT(start()));
    Red_State->addTransition(&timer1,SIGNAL(timeout()),RedCloseState);

    QObject::connect(RedCloseState,SIGNAL(entered ()),&timer1,SLOT(start()));
    RedCloseState->addTransition(&timer1, SIGNAL(timeout()), Red_State);

    QObject::connect(&timer2,SIGNAL(timeout()),&timer1,SLOT(start()));


    //黄灯闪烁
    QObject::connect(Yellow_State,SIGNAL(entered()) , &timer1 , SLOT(start()));
    Yellow_State->addTransition(&timer1, SIGNAL(timeout()) , YellowCloseState);

    QObject::connect(YellowCloseState,SIGNAL(entered()) , &timer1 , SLOT(start()));
    YellowCloseState->addTransition(&timer1, SIGNAL(timeout()) , Yellow_State);

    QObject::connect(&timer2,SIGNAL(timeout()),&timer1,SLOT(start()));
    //黄灯返回闪烁
    QObject::connect(Yellow_State1,SIGNAL(entered()) , &timer1 , SLOT(start()));
    Yellow_State1->addTransition(&timer1, SIGNAL(timeout()) , YellowCloseState1);

    QObject::connect(YellowCloseState1,SIGNAL(entered()) , &timer1 , SLOT(start()));
    YellowCloseState1->addTransition(&timer1, SIGNAL(timeout()) , Yellow_State1);
    QObject::connect(&timer2,SIGNAL(timeout()),&timer1,SLOT(start()));

    //绿灯闪烁
    QObject::connect(Green_State,SIGNAL(entered()) , &timer1 , SLOT(start()));
    Green_State->addTransition(&timer1,SIGNAL(timeout()),GreenCloseState);

    QObject::connect(GreenCloseState,SIGNAL(entered()) , &timer1 , SLOT(start()));
    GreenCloseState->addTransition(&timer1,SIGNAL(timeout()),Green_State);

    QObject::connect(&timer2,SIGNAL(timeout()),&timer1,SLOT(start()));

    //各个灯之间的转换
    QObject::connect(RedState,SIGNAL(entered ()),&timer2,SLOT(start()));
    RedState->addTransition(&timer2, SIGNAL(timeout()), RedCoruscate);

    QObject::connect(RedCoruscate,SIGNAL(entered()),&timer2,SLOT(start()));
    RedCoruscate->addTransition(&timer2,SIGNAL(timeout()),YellowState);

    QObject::connect(YellowState,SIGNAL(entered()),&timer2,SLOT(start()));
    YellowState->addTransition(&timer2,SIGNAL(timeout()),YellowCoruscate);

    QObject::connect(YellowCoruscate,SIGNAL(entered()),&timer2,SLOT(start()));
    YellowCoruscate->addTransition(&timer2,SIGNAL(timeout()),GreenState);

    QObject::connect(GreenState,SIGNAL(entered()),&timer2,SLOT(start()));
    GreenState->addTransition(&timer2,SIGNAL(timeout()),GreenCoruscate);

    QObject::connect(GreenCoruscate,SIGNAL(entered()),&timer2,SLOT(start()));
    GreenCoruscate->addTransition(&timer2,SIGNAL(timeout()),YellowState1);//开始返回

    QObject::connect(YellowState1,SIGNAL(entered()),&timer2,SLOT(start()));
    YellowState1->addTransition(&timer2,SIGNAL(timeout()),YellowCoruscate1);

    QObject::connect(YellowCoruscate1,SIGNAL(entered()),&timer2,SLOT(start()));
    YellowCoruscate1->addTransition(&timer2,SIGNAL(timeout()),RedState);



    QStateMachine machine;
    machine.addState(RedState);
    machine.addState(RedCoruscate);

    machine.addState(YellowState1);
    machine.addState(YellowCoruscate1);

    machine.addState(YellowState);
    machine.addState(YellowCoruscate);

    machine.addState(GreenState);
    machine.addState(GreenCoruscate);

    machine.setInitialState(RedState);
    machine.start();

    //把灯放如镜头
    scene.addItem(light);

    //初始化自定义场景，可以更灵活的显示要显示的内容
    MyView view(&scene);
    view.resize(G_w , G_h*3);
    view.show();



    QTimer timer;
    QObject::connect(&timer , SIGNAL(timeout()) , &scene , SLOT(update()));
    timer.start(100/33);


    return a.exec();
}
