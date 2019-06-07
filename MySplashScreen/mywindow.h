#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtGui>

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    MyWindow(QWidget *parent = 0);
    ~MyWindow();

    void createToolBars();
    void createStatusBar();

private:
    QToolBar *FileToolBar;
    QToolBar *EditToolBar;

    QAction *newAct;
};

#endif // MYWINDOW_H
