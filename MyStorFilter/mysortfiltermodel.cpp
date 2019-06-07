#include "mysortfiltermodel.h"

MySortFilterModel::MySortFilterModel(QWidget *parent)
    : QWidget(parent)
{
    ReadPos();
    CureateMyUI();
    SetDataToModel();
    //setMinimumSize(500,450);
   // setMaximumSize(500,450);

}

MySortFilterModel::~MySortFilterModel()
{

}


void MySortFilterModel::CureateMyUI()
{
//第一个布局管理器
    OrigGbox = new QGroupBox(tr("Original Model"));
    layout1 = new QVBoxLayout;
    OrigTview = new QTreeView;
    layout1->addWidget(OrigTview);
    OrigGbox->setLayout(layout1);

//第二个布局管理器
    SortGbox = new QGroupBox(tr("Sorted/Filtered Model"));
    SortTview = new QTreeView;
    layout2 = new QVBoxLayout;
    layout2->addWidget(SortTview);
    SortGbox->setLayout(layout2);

   /* formLayout = new QFormLayout ;
    formLayout->addRow(new QLabel(tr("Filter pattern")),new QLineEdit);*/

//第三个布局管理器
    layout3 = new QGridLayout ;
    L_Patt = new QLabel(tr("&Filter pattern:"));
    L_Syn = new QLabel(tr("Filter &syntax:"));
    L_Column = new QLabel(tr("Filter &column:"));

    Patt_edit = new QLineEdit;
    Cb_Syn = new QComboBox;
    Cb_Column = new QComboBox;

    L_Patt->setBuddy(Patt_edit);
    L_Syn->setBuddy(Cb_Syn);
    L_Column->setBuddy(Cb_Column);

    layout3->addWidget(L_Patt,0,0);
    layout3->addWidget(Patt_edit,0,1);

    layout3->addWidget(L_Syn,1,0,1,1);
    layout3->addWidget(Cb_Syn,1,1,1,1);

    layout3->addWidget(L_Column,2,0,1,1);
    layout3->addWidget(Cb_Column,2,1,1,1);

//第四个布局管理器
    Ck_filter = new QCheckBox(tr("Case sensitive fillter"));
    Ck_Sort = new QCheckBox(tr("Case sensitive sorting"));
    layout4 = new QHBoxLayout;
    layout4->addWidget(Ck_filter);
    layout4->addStretch();
    layout4->addWidget(Ck_Sort);
    layout4->setMargin(10);



    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(OrigGbox);
    mainLayout->addWidget(SortGbox);
    mainLayout->addLayout(layout3);
    mainLayout->addLayout(layout4);
    setLayout(mainLayout);
}

void MySortFilterModel::SetDataToModel()
{
    model = new QStandardItemModel(0,3,this);
    model->setHeaderData(0,Qt::Horizontal,tr("Name"));
    model->setHeaderData(1,Qt::Horizontal,tr("Sex"));
    model->setHeaderData(2,Qt::Horizontal,tr("Age"));

    QString Name[8]={"LSY","RHZ","Z Y","NXY","ZML","SLY","W L","W F"};
    QString Sex[8] ={"Boy","Girl","Nv","Nv","Nv","Nv","Nv","Nv"};
    QString Age[8] = {"20","20","19","18","21","22","18","19"};
    for(int n=0;n<8;n++)
    {
        model->insertRow(0);
    }

    for(int i=0,j=0;i<8;i++)
    {


        model->setData(model->index(i,j),Name[i]);
        j++;
        model->setData(model->index(i,j),Sex[i]);
        j++;
        model->setData(model->index(i,j),Age[i]);
        j++;
        if(j == 3)
        {
            j = 0;
        }
    }
    // 用于判断是否交替的显示行的颜色
    OrigTview->setAlternatingRowColors(true);//设置每行颜色不同
    // OrigTview->setShowGrid(false);//去掉网格//用QTreeView不需要去掉网格
    //rootIsDecorated: 该属性保存一个bool类型， 用于判断是否显示展开和收起子项的控制
    OrigTview->setRootIsDecorated(true);
    OrigTview->setModel(model);

    //在数据模型和一个视图之间提供数据的排序和过滤
    proxyModel = new QSortFilterProxyModel;
    proxyModel->setDynamicSortFilter(true);
    //把实际模型加入一个虚拟模型
    proxyModel->setSourceModel(model);

    /*
      Qt::DescendingOrder 从大到小排列
      Qt::AscendingOrder  从小到大排列
     */
    SortTview->sortByColumn(2,Qt::AscendingOrder);//指定列从小(大)到大(小)排列

    //排序 该属性保存一个bool类型， 用于判断是否使用排序功能
    SortTview->setSortingEnabled(true);
    //改变每一行颜色
    SortTview->setAlternatingRowColors(true);
    //把虚拟模型加入实际模型中
    SortTview->setModel(proxyModel);

    Cb_Column->addItem("Name",0);
    Cb_Column->addItem("Sex",1);
    Cb_Column->addItem("Age",2);

    Cb_Syn->addItem("RegExp",0);
    Cb_Syn->addItem("Wildcard",1);
    Cb_Syn->addItem("Fixed string",2);


    Ck_filter->setChecked(true);
    Ck_Sort->setChecked(true);
    //单行文本编辑框字符改变
    connect(Patt_edit,SIGNAL(textChanged(QString)),this,SLOT(PatternChanged(QString)));

    //QComboBox列发生变化
    connect(Cb_Column,SIGNAL(currentIndexChanged(int)),this,SLOT(CB_ColumnChanged()));


}

void MySortFilterModel::PatternChanged(QString)
{
    //判断复选框中是否被选中,如果选中则返回敏感，否则返回不敏感。
    /*枚举类型 Qt::CaseSensitivity
      包含的值
      Qt::CaseInsensitive  ：  大小写不敏感
      Qt::CaseSensitive    ：  大小写敏感
      */
    Qt::CaseSensitivity caseSensitive = Ck_filter->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

    //获取filter syntax
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(Cb_Syn->itemData(Cb_Syn->currentIndex()).toInt());

    //为指定的模型构建一个正则表达式
    QRegExp regExp( Patt_edit->text(), caseSensitive, syntax);

    //把构建的正则表达式加入模型
    proxyModel->setFilterRegExp(regExp);
}

 void MySortFilterModel::CB_ColumnChanged()
 {
     proxyModel->setFilterKeyColumn(Cb_Column->currentIndex());
 }
 //窗口关闭，写入位置记录
 void MySortFilterModel::closeEvent ( QCloseEvent * )
 {
     SetPos();
 }
//读位置
 void MySortFilterModel::ReadPos()
 {
     QSettings settings("LSY","Model");
     QPoint pos = settings.value("pos",QPoint(330,310)).toPoint();
     QSize  size = settings.value("size",QSize(500,450)).toSize();
     resize(size);

     move(pos);
 }
 //写位置
 void MySortFilterModel::SetPos()
 {
     QSettings settings("LSY","Model");
     settings.setValue("pos",pos());
     settings.setValue("size",size());
 }
