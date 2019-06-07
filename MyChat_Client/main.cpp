#include <QtGui/QApplication>
#include "myclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient w;
    w.show();

    return a.exec();
}
