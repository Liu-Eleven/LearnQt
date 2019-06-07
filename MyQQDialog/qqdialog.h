#ifndef QQDIALOG_H
#define QQDIALOG_H

#include <QtGui>

class QQDialog : public QDialog
{
    Q_OBJECT

public:
    QQDialog(QWidget *parent = 0);
    ~QQDialog();
private slots:
    bool OpenFile();
private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLabel *MyOther;
    QLabel *MyIcon;

    QLineEdit *LineEditUser;
    QLineEdit *LineEditName;
    QLineEdit *LineEditAge;
    QLineEdit *LineEditBak;

    QComboBox *comboBoxSex;

    QTextEdit *textEditDepartment;
    QTextEdit *textEditDisc;

    QPushButton *pushButtonIcon;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonExit;

    void CreateUi();
};

#endif // QQDIALOG_H
