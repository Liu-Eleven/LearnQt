#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QTextCodec::setCodecForTr();
    QTextCodec *code =  QTextCodec::codecForName("UTF8");
    QTextCodec::setCodecForTr(code);
    QTextCodec::setCodecForLocale(code);
    QTextCodec::setCodecForCStrings(code);
    TcpServer w;
    w.show();

    return a.exec();
}
