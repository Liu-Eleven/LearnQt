#include "dockwindow.h"

DockWIndow::DockWIndow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("停靠窗口"));
    QTextEdit *te = new QTextEdit(this);
    te->setText(tr("主窗口"));
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);

    //停靠窗口1
    QDockWidget *dock = new QDockWidget(tr("停靠窗口1"),this);
    //void setAllowedAreas(Qt::DockWidgetAreas areas);
    /*参数：
      Qt::LeftDockWidgetArea: //可在主窗口的左侧停靠
      Qt::RightDockWidgetArea //可在主窗口的右侧停靠
      Qt::TopDockWidgetArea   //可在主窗口的顶端停靠
      Qt::BottomDockWidgetArea//可在主窗口的底端停靠
      Qt::AllDockWidgetAreas  //可在主窗口的任意部位停靠
      Qt::NoDockWidgetArea    //只可停靠在插入处
     */
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QTextEdit *te1 = new QTextEdit;
    te1->setText(tr("窗口1可以在Mainwindow窗口的左部和右部停靠，不可浮动，不可关闭"));
    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //停靠窗口2
    dock = new QDockWidget(tr("停靠窗口2"),this);
    //void setFeatures(DockWidgetFeatures features);
    /*
      参数：
      QDockWidget::DockWidgetClosable //停靠窗口可关闭，右上角的关闭按钮
      QDockWidget::DockWidgetMovable  //停靠窗口可移动
      QDockWidget::DockWidgetFloatable//停靠窗口可浮动
      QDockWidget::AllDockWidgetFeatures//此参数表示拥有停靠窗口的所有特性
      QDockWidget::NoDockWidgetFeatures //不可移动/不可关闭/不可浮动
     */
    dock->setFeatures(QDockWidget::DockWidgetFloatable );
    QTextEdit *te2 = new QTextEdit;
    te2->setText(tr("窗口2只可浮动，不可关闭"));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    //停靠窗口2
    dock = new QDockWidget(tr("停靠窗口3"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *te3 = new QTextEdit;
    te3->setText(tr("窗口3可浮动，可关闭"));
    dock->setWidget(te3);
    addDockWidget(Qt::BottomDockWidgetArea,dock);

}

DockWIndow::~DockWIndow()
{

}
