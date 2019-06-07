#ifndef RGBLIGHT_H
#define RGBLIGHT_H

#include "mylight.h"
#include <QtGui>

class RGBLight : public QWidget
{
    Q_OBJECT

public:
    RGBLight(QWidget *parent = 0);
    ~RGBLight();
private:
    void CreatLight();
};

#endif // RGBLIGHT_H
