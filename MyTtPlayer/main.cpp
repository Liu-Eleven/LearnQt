#include <QtGui/QApplication>
#include "myttplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTtPlayer w;
    w.show();

    return a.exec();
}
