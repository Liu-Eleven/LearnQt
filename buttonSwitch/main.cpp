#include <QtGui>

//void ReadSetting();
//void WriteSetting();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton Btn;

    QState *Off = new QState ;
    Off->assignProperty(&Btn,"text",QObject::tr("Off"));
    //Off->setObjectName("LSY");

    QState *On = new QState ;
    On->assignProperty(&Btn,"text",QObject::tr("On"));


    //提供一个层次化的有限状态机
    QStateMachine Btn_Machine;
    //在状态机中添加状态
    Btn_Machine.addState(Off);
    Btn_Machine.addState(On);

    //设置状态机的初始状态
    Btn_Machine.setInitialState(Off);

    //启动状态机制
    Btn_Machine.start();

    //给按钮添加事件
    Off->addTransition(&Btn,SIGNAL(clicked()),On);
    On->addTransition(&Btn,SIGNAL(clicked()),Off);
    Btn.show();

    return a.exec();
}


