#include <QTextCodec>
#include "chinese.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QTranslator transloator(0);
    transloator.load("chinese_zh",".");
    a.installTranslator(&transloator);

    Chinese w;
    w.show();

    return a.exec();
}
