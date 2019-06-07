#ifndef CONTROLMOVE_H
#define CONTROLMOVE_H

#include <QtGui>

class ControlMove : public QWidget
{
    Q_OBJECT

public:
    ControlMove(QWidget *parent = 0);
    ~ControlMove();

    void drawPix();
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);

private:
    QPixmap *pix;
    QImage image;

    int startX;
    int startY;
    int width;
    int height;

    int step;
};

#endif // CONTROLMOVE_H
