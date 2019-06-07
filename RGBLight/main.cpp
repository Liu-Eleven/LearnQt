#include "rgblight.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    RGBLight w;
    w.show();

    return a.exec();
}
