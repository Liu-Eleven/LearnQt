#include "mywindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/splash.bmp");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();

    MyWindow w;
    w.show();
    splash.finish(&w);

    return a.exec();
}

/*
  这是一个给程序添加屏风的例子
*/
