#ifndef MYSORTFILTERMODEL_H
#define MYSORTFILTERMODEL_H

#include <QtGui>

class MySortFilterModel : public QWidget
{
    Q_OBJECT

public:
    MySortFilterModel(QWidget *parent = 0);
    ~MySortFilterModel();
protected:
    void closeEvent ( QCloseEvent * event );

private slots:
    void PatternChanged(QString);
    void CB_ColumnChanged();

private:
    QGroupBox *OrigGbox;
    QTreeView *OrigTview;//QTableView

    QGroupBox *SortGbox;
    QTreeView *SortTview;

    QLabel *L_Patt;
    QLabel *L_Syn;
    QLabel *L_Column;

    QLineEdit *Patt_edit;
    QComboBox *Cb_Syn;
    QComboBox *Cb_Column;

    QCheckBox *Ck_filter;
    QCheckBox *Ck_Sort;

    QVBoxLayout *mainLayout ;
    //QFormLayout *formLayout;
    QVBoxLayout *layout1;
    QVBoxLayout *layout2;
    QGridLayout *layout3;
    QHBoxLayout *layout4;

    QStandardItemModel *model;
    //在数据模型和一个视图之间提供数据的排序和过滤
    QSortFilterProxyModel *proxyModel;

    void SetDataToModel();
    void CureateMyUI();

    void ReadPos();
    void SetPos();
};

#endif // MYSORTFILTERMODEL_H
