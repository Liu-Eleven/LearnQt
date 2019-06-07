#include <QtGui/QApplication>
#include "dragword.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *mainWidget = new QWidget;
    QTextEdit *edit = new QTextEdit;
    edit->setText("Since we will ...");

    DragWord *dragword = new DragWord;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(edit);
    layout->addWidget(dragword);

    layout->setStretchFactor(edit,1);
    layout->setStretchFactor(dragword, 3);
    mainWidget->setLayout(layout);
    mainWidget->show();

    return a.exec();
}
