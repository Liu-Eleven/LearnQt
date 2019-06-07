#include <QtGui/QApplication>
#include "datarw.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    DataRW w;
    w.show();

    return a.exec();
}
