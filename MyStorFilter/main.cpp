#include <QtGui/QApplication>
#include "mysortfiltermodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySortFilterModel w;
    w.show();

    return a.exec();
}
