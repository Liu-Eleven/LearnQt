#ifndef DATARW_H
#define DATARW_H

#include <QtGui>

class DataRW : public QDialog
{
    Q_OBJECT

public:
    DataRW(QWidget *parent = 0);
    ~DataRW();
private slots:
    void GetData();
    void SaveData();
private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *timeLabel;

    QPushButton *SaveButton;
    QPushButton *GetButton;

    QComboBox *PowerComboBox;
    QSpinBox *ChangeSpinBox;
    QLineEdit *frequencyEdit;

    void CreateUi();

};

#endif // DATARW_H
