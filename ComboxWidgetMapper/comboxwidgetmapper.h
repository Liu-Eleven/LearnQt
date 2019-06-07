#ifndef COMBOXWIDGETMAPPER_H
#define COMBOXWIDGETMAPPER_H

#include <QtGui>

class ComboxWidgetMapper : public QWidget
{
    Q_OBJECT

public:
    ComboxWidgetMapper(QWidget *parent = 0);
    ~ComboxWidgetMapper();
private slots:
    void UpdateButtons(int );


private:
    QLabel *L_Name ;
    QLabel *L_Addr ;
    QLabel *L_Type ;

    QLineEdit *Edit_Name ;
    QTextEdit *Text_Addr ;

    QComboBox *Com_Type ;

    QPushButton *Btn_Previous ;
    QPushButton *Btn_Next ;

    QGridLayout *MainLayout ;

    QStandardItemModel *model ;
    QStringListModel *TypeModel;
    QDataWidgetMapper *mapper ;

    void CreateUI();
    void SetUpModel();


};

#endif // COMBOXWIDGETMAPPER_H
