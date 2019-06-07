#include <QtGui/QApplication>
#include "dynamicbutton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator(0);
    translator.load("eventfilter_zh",".");
    a.installTranslator(&translator);

    DynamicButton *w = new DynamicButton;
    w->show();



    return a.exec();
}
