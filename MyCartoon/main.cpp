#include <QtGui/QApplication>
#include "myblock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene Scene ;
    Scene.setSceneRect(0,0,300,300);
    Scene.setBackgroundBrush(Qt::black);

    //QColor color= QColor(qrand()%255,qrand()%255,qrand()%255);

    MyBlock *block = new MyBlock(0);
    MyBlock *block1 = new MyBlock(0);

    Scene.addItem(block);
    Scene.addItem(block1);//往镜头里边添加一个要显示的物品

    //block.setPos(150-25,150-25);//设置块的位置

    QPropertyAnimation *animation = new QPropertyAnimation(block ,"pos");

    //animation->setDirection(QAbstractAnimation::Backward);//反方向跑

    animation->setStartValue(QPointF(0,0));//开始位置
    animation->setKeyValueAt(0.25,QPointF(300-50,0));//中转位置
    animation->setKeyValueAt(0.5,QPointF(300-50,300-50));
    animation->setKeyValueAt(0.75,QPointF(0,300-50));
    animation->setEndValue(QPointF(0,0));//结束位置

    animation->setDuration(3000);//在3秒中跑完轨道
    //animation->setEasingCurve(QEasingCurve::OutBounce);//像弹球一样落下

    //第二个轨道
    QPropertyAnimation *animation2 = new QPropertyAnimation(block1 ,"pos");
    animation2->setStartValue(QPointF(0,0));//开始位置
    animation2->setKeyValueAt(0.25,QPointF(0,300-50));//中转位置
    animation2->setKeyValueAt(0.5,QPointF(300-50,300-50));//中转位置
    animation2->setKeyValueAt(0.75,QPointF(300-50,0));//中转位置
    animation2->setEndValue(QPointF(0,0));//结束位置
    animation2->setDuration(3000);
   // animation2->setEasingCurve(QEasingCurve::OutBounce);


    //QSequentialAnimationGroup: 把多个动画按队列次序依次播放
    QSequentialAnimationGroup *AnimationGroup = new QSequentialAnimationGroup;
    AnimationGroup->addAnimation(animation);

    QSequentialAnimationGroup *AnimationGroup2 = new QSequentialAnimationGroup;
    AnimationGroup2->addAnimation(animation2);

    //QParallelAnimationGroup : 把多个动画放在一个组中， 并发的播放
    QParallelAnimationGroup  *AllGroup = new QParallelAnimationGroup;
    AllGroup->addAnimation(AnimationGroup);
    AllGroup->addAnimation(AnimationGroup2);

    AllGroup->start();
    AllGroup->setLoopCount(-1);//循环播放


    QGraphicsView view(&Scene);//把镜头射向显示器
    view.show();
    return a.exec();
}
