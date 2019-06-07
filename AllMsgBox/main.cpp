#include <QtGui/QApplication>
#include "msgbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MsgBox w;
    w.show();

    return a.exec();
}
