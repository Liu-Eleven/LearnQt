#include <QtGui/QApplication>
#include "dockwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    DockWIndow w;
    w.show();

    return a.exec();
}
