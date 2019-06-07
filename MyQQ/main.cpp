#include <QtGui/QApplication>
#include "myqq.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyQQ w;
    w.show();

    return a.exec();
}
