#include <QtGui/QApplication>
#include "mycursor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyCursor w;
    w.show();

    return a.exec();
}

/*
  本程序展示了鼠标指针的变化
*/
