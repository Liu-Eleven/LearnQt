/********************************************************************************
** Form generated from reading UI file 'exer1.ui'
**
** Created: Sun Dec 18 18:43:07 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXER1_H
#define UI_EXER1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Exer1
{
public:

    void setupUi(QWidget *Exer1)
    {
        if (Exer1->objectName().isEmpty())
            Exer1->setObjectName(QString::fromUtf8("Exer1"));
        Exer1->resize(400, 300);

        retranslateUi(Exer1);

        QMetaObject::connectSlotsByName(Exer1);
    } // setupUi

    void retranslateUi(QWidget *Exer1)
    {
        Exer1->setWindowTitle(QApplication::translate("Exer1", "Exer1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Exer1: public Ui_Exer1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXER1_H
