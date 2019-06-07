#include <QtGui/QApplication>
#include "myaddrbook.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyAddrBook w;
    w.show();


    return a.exec();
}
