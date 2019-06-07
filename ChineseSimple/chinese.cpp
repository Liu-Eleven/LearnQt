#include "chinese.h"

Chinese::Chinese(QWidget *parent)
    : QWidget(parent)
{
    QFont font("ZYSong18030",12);
    setFont(font);

    btn = new QPushButton(tr("终于可以写中文了!"));
    QGridLayout *g = new QGridLayout;
    g->addWidget(btn);

    setWindowTitle(tr("中文"));
    setLayout(g);
}

Chinese::~Chinese()
{

}
