#include "myqq.h"

MyQQ::MyQQ( QWidget * parent , Qt::WindowFlags f)
    : QToolBox(parent,f)
{
    setMaximumWidth(158);
    setWindowTitle("LSY ~ QQ");
    //我的好友
    QGroupBox *groupBox1 = new QGroupBox ;
    //好友：1
    toolBtn1_1 = new QToolButton ;
    //toolBtn1_1->setEnabled(false);//设置好友不在线
    toolBtn1_1->setText(tr("LiuShiYi"));
    toolBtn1_1->setIcon(QPixmap("./images/lsy.png"));
    toolBtn1_1->setIconSize(QPixmap("./images/lsy.png").size());

    //设置为true鼠标离开后按钮自动恢复成谈起状态。
    toolBtn1_1->setAutoRaise(true);

    /*
      ToolButtonStyle属性主要来描述按钮的文字和图片的显示方式，Qt定义了4种ToolButtonStyle类型：
      Qt::ToolButtonIconOnly 只显示图片
      Qt::ToolButtonTextOnly 只显示文字
      Qt::ToolButtonTextBesideIcon 文字在图片旁边
      Qt::ToolButtonTextUnderIcon 文字在图片下边

    */
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    //好友：2

    toolBtn1_2 = new QToolButton ;
    toolBtn1_2->setText(tr("NiuXinYuan"));
    toolBtn1_2->setIcon(QPixmap("./images/nxy.png"));
    toolBtn1_2->setIconSize(QPixmap("./images/nxy.png").size());
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //好友：3
    toolBtn1_3 = new QToolButton ;
    toolBtn1_3->setText(tr("WeiHaiYun"));
    toolBtn1_3->setIcon(QPixmap("./images/WHY.png"));
    toolBtn1_3->setIconSize(QPixmap("./images/WHY.png").size());
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //好友：4
    toolBtn1_4 = new QToolButton ;
    toolBtn1_4->setText(tr("WangQuan"));
    toolBtn1_4->setIcon(QPixmap("./images/WQ.png"));
    toolBtn1_4->setIconSize(QPixmap("./images/WQ.png").size());
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    //好友：5
    toolBtn1_5 = new QToolButton ;
    toolBtn1_5->setText(tr("WangLi"));
    toolBtn1_5->setIcon(QPixmap("./images/wl.png"));
   // toolBtn1_5->setIconSize(QPixmap("./images/wl.png").size());
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);
    layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignHCenter);
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addWidget(toolBtn1_4);
    layout1->addWidget(toolBtn1_5);
    layout1->addStretch();

    //陌生人
    QGroupBox *groupBox2 = new QGroupBox ;
    toolBtn2_1 = new QToolButton;
    toolBtn2_1->setText(tr("ZhouYan"));
    toolBtn2_1->setIcon(QPixmap("./images/ZY.png"));
    toolBtn2_1->setIconSize(QPixmap("./images/ZY.png").size());
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    toolBtn2_2 = new QToolButton;
    toolBtn2_2->setText(tr("WangYing"));
    toolBtn2_2->setIcon(QPixmap("./images/wy.png"));
    toolBtn2_2->setIconSize(QPixmap("./images/wy.png").size());
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);
    layout2->addStretch();
    //黑名单
    QGroupBox *groupBox3 = new QGroupBox ;
    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText(tr("UnKnow"));
    toolBtn3_1->setIcon(QPixmap("./images/def.png"));
    toolBtn3_1->setIconSize(QPixmap("./images/def.png").size());
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    toolBtn3_2 = new QToolButton;
    toolBtn3_2->setText(tr("Group"));
    toolBtn3_2->setIcon(QPixmap("./images/group.png"));
    toolBtn3_2->setIconSize(QPixmap("./images/group.png").size());
    toolBtn3_2->setAutoRaise(true);
    toolBtn3_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);
    layout3->addStretch();



    this->addItem((QWidget *)groupBox1 , tr("My friends"));
    this->addItem((QWidget *)groupBox2 , tr("Stranger"));
    this->addItem((QWidget *)groupBox3 , tr("Black List"));
}

MyQQ::~MyQQ()
{

}
