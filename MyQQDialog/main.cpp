#include <QtGui/QApplication>
#include "qqdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQDialog w;
    w.show();

    return a.exec();
}
