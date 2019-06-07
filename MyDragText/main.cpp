#include <QtGui/QApplication>
#include "dragtext.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    DragText w;
    w.show();

    return a.exec();
}
