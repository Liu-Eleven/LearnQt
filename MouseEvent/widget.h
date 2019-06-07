#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *Btn;
};

#endif // WIDGET_H
