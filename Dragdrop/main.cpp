#include "mydragdrop.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget MainWidget;
    QHBoxLayout *hbMain = new QHBoxLayout;
    hbMain->addWidget(new Mydragdrop);
    hbMain->addWidget(new Mydragdrop);

    MainWidget.setLayout(hbMain);
    MainWidget.show();

    return a.exec();
}
