#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    Btn = new QPushButton(this) ;
    //设置按钮在水平方向和垂直方向可扩展
    Btn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    QVBoxLayout *Layout = new QVBoxLayout ;
    Layout->addWidget(Btn);
    Layout->setMargin(61);//本句和下句效果一样
    //Layout->setContentsMargins(61,61,61,61);

    QState *State1 = new QState;
    QState *State2 = new QState;
    QState *State3 = new QState;
    //QState *State4 = new QState;

    State1->assignProperty(Btn,"text","Inside");
    State2->assignProperty(Btn,"text","Outside");
    State3->assignProperty(Btn,"text","Pressing...");
    //State4->assignProperty(Btn,"text","Release!");

    QStateMachine *Machine = new QStateMachine(this);

//当鼠标按下时。。。
    //QEventTransition: 绑定一个事件到特定的QObject
    QEventTransition *EnterEvent = new QEventTransition(Btn,QEvent::Enter);
    //属性targetState: 保存该变化的目标状态
    EnterEvent->setTargetState(State1);
    //void QState::addTransition ( QAbstractTransition * transition )
    //在该状态中添加一个变化
    State2->addTransition(EnterEvent);
//当鼠标离开时。。。
    QEventTransition *LeaveEvent = new QEventTransition(Btn,QEvent::Leave);
    LeaveEvent->setTargetState(State2);
    State1->addTransition(LeaveEvent);
//当鼠标压下时。。。
    QEventTransition *PressEvent = new QEventTransition(Btn,QEvent::MouseButtonPress);
    PressEvent->setTargetState(State3);
    State1->addTransition(PressEvent);
//当鼠标松开时。。。
    QEventTransition *ReleaseEvent = new QEventTransition(Btn,QEvent::MouseButtonRelease);
    ReleaseEvent->setTargetState(State1);
    State3->addTransition(ReleaseEvent);

    Machine->addState(State1);
    Machine->addState(State2);
    Machine->addState(State3);
    //Machine->addState(State4);
    //设置状态机的初始状态
    Machine->setInitialState(State2);
    Machine->start();



    setLayout(Layout);
    resize(300,300);
}

Widget::~Widget()
{

}
