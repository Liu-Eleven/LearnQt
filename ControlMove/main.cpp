#include <QtGui/QApplication>
#include "controlmove.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlMove w;
    w.show();

    return a.exec();
}
