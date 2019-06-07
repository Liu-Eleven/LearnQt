#ifndef CHINESE_H
#define CHINESE_H

#include <QtGui>

class Chinese : public QWidget
{
    Q_OBJECT

public:
    Chinese(QWidget *parent = 0);
    ~Chinese();

private:
    QPushButton *btn;
};

#endif // CHINESE_H
