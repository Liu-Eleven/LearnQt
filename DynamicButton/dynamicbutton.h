#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include <QtGui>

class DynamicButton : public QDialog
{
    Q_OBJECT

public:
    DynamicButton( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    ~DynamicButton();

private slots:
    bool eventFilter(QObject *, QEvent *);

private:

    QLabel *label11;
    QLabel *label2;
    QLabel *label3;

    QLabel *labelState;

    QImage image1;
    QImage image2;
    QImage image3;


};

#endif // DYNAMICBUTTON_H
