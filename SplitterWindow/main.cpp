#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    //主分割窗口                             //水平分割窗口
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,0);
    QTextEdit *textLeft = new QTextEdit(QObject::tr("左边框"),splitterMain);
    //设置文字对齐方式
    textLeft->setAlignment(Qt::AlignCenter);

    //右部分割窗口
    QSplitter *splitterRight = new QSplitter(Qt::Vertical,splitterMain);
    //设定分割窗口分割条在拖动时是否为时事更新显示
    splitterRight->setOpaqueResize(false);
    QTextEdit *textUp = new QTextEdit(QObject::tr("右上角边框"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom = new QTextEdit(QObject::tr("右下角边框"),splitterRight);

    //设置文字对齐方式
   /* Qt::AlignLeft; // 左对齐
    Qt::AlignRight;  // 右对齐
    Qt::AlignCenter; // 文字居中
    Qt::AlignHCenter;// 水平居中
    Qt::AlignVCenter;//垂直居中
    Qt::AlignTop;     //文字与顶端对齐
    Qt::AlignBottom; //文字与底部对齐
    */

    textBottom->setAlignment(Qt::AlignCenter);

    //void QSplitter::setStretchFactor ( int index, int stretch )
    //index 指定设置的控件序号，控件序号按插入次序从0依次编号，stretch大于0
    //表示此控件为可伸缩
    splitterMain->setStretchFactor(1,1);
    splitterMain->setWindowTitle(QObject::tr("窗口分割"));
    splitterMain->show();



    return a.exec();
}
