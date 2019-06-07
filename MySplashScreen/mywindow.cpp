#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Splash Example");

    QTextEdit *edit = new QTextEdit;
    edit->setText("Splash Example!");
    setCentralWidget(edit);

    createToolBars();
    createStatusBar();
    resize(600,450);
    sleep(2);
}

MyWindow::~MyWindow()
{

}


void MyWindow::createToolBars()
{
    qDebug()<<"lsy";
    newAct = new QAction(QIcon(":/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    //动作提示
    newAct->setStatusTip(tr("Create a new file"));


    FileToolBar = addToolBar(tr("File"));
    FileToolBar->addAction(newAct);
    EditToolBar = addToolBar(tr("Edit"));

}
void MyWindow::createStatusBar()
{
    statusBar()->showMessage(tr("this is splash example!"));
}
