#include <QtGui/QApplication>
#include "comboxwidgetmapper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ComboxWidgetMapper w;
    w.show();

    return a.exec();
}
