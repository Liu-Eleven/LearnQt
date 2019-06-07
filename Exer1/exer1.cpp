#include "exer1.h"
#include "ui_exer1.h"

Exer1::Exer1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Exer1)
{
    ui->setupUi(this);
}

Exer1::~Exer1()
{
    delete ui;
}
