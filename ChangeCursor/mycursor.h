#ifndef MYCURSOR_H
#define MYCURSOR_H

#include <QtGui>

class MyCursor : public QWidget
{
    Q_OBJECT

public:
    MyCursor(QWidget *parent = 0);
    ~MyCursor();
    void CreateUi();

private slots:
    void SetOneCurs();
    void SetTwoCurs();
    void SetThreeCurs();
    void SetFourCurs();
    void SetFiveCurs();
    void SetSixCurs();
    void SetSevenCurs();
    void SetEightCurs();
    void SetNineCurs();
    void SetTenCurs();
    void SetElevenCurs();
    void SetTwelveCurs();
    void SetThirteenCurs();
    void SetFourteenCurs();
    void SetFifteenCurs();
    void SetSixteenCurs();
    void SetSeventeenCurs();
    void SetEighteenCurs();
    void SetNineteenCurs();


private:
    QGridLayout *MainLayout;
    QPushButton *label1;
    QPushButton *label2;
    QPushButton *label3;
    QPushButton *label4;
    QPushButton *label5;
    QPushButton *label6;
    QPushButton *label7;
    QPushButton *label8;
    QPushButton *label9;
    QPushButton *label10;
    QPushButton *label11;
    QPushButton *label12;
    QPushButton *label13;
    QPushButton *label14;
    QPushButton *label15;
    QPushButton *label16;
    QPushButton *label17;
    QPushButton *label18;
    QPushButton *label19;

};

#endif // MYCURSOR_H
