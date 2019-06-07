#include "comboxwidgetmapper.h"


ComboxWidgetMapper::ComboxWidgetMapper(QWidget *parent)
    : QWidget(parent)
{
    SetUpModel();
    CreateUI();
    setLayout(MainLayout);


}

ComboxWidgetMapper::~ComboxWidgetMapper()
{

}

void ComboxWidgetMapper::CreateUI()
{
    L_Name = new QLabel(tr("&Name:"));
    L_Addr = new QLabel(tr("A&ddress:"));
    L_Type = new QLabel(tr("&Type:"));

    Edit_Name = new QLineEdit;
    Edit_Name->setReadOnly(true);
    Text_Addr = new QTextEdit;

    Com_Type = new QComboBox ;

    Btn_Previous = new QPushButton(tr("&Previous"));
    Btn_Previous->setEnabled(false);
    Btn_Next = new QPushButton(tr("&Next"));
    MainLayout = new QGridLayout ;

    L_Name->setBuddy(Edit_Name);
    L_Addr->setBuddy(Text_Addr);
    L_Type->setBuddy(Com_Type);

    Com_Type->setModel(TypeModel);//设置组合框里面数据

    // QDataWidgetMapper::把可视控件和数据模型的一列映射起来
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);

    //在数据模型的section列和可视控件widget之间建立映射
    mapper->addMapping(Edit_Name,0);
    mapper->addMapping(Text_Addr,1);
    mapper->addMapping(Com_Type,2,"currentIndex");

    mapper->toFirst();//滚到第一行或列[slot]



    MainLayout->addWidget(L_Name,0,0,1,1);
    MainLayout->addWidget(Edit_Name,0,1,1,1);
    MainLayout->addWidget(Btn_Previous,0,2,1,1);

    MainLayout->addWidget(L_Addr,1,0,1,1);
    MainLayout->addWidget(Text_Addr,1,1,2,1);//文本编辑域占两行
    MainLayout->addWidget(Btn_Next,1,2,1,1);

    MainLayout->addWidget(L_Type,3,0,1,1);
    MainLayout->addWidget(Com_Type,3,1,1,1);

    //建立信号槽
    connect(Btn_Previous,SIGNAL(clicked()),mapper,SLOT(toPrevious()));//向前
    connect(Btn_Next,SIGNAL(clicked()),mapper,SLOT(toNext()));//下一个
    //更新按钮信号槽
    connect(mapper,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateButtons(int)));




}

void ComboxWidgetMapper::SetUpModel()
{
    QStringList items ;
    items<<tr("Home") <<tr("Work")<<tr("Other");
    TypeModel = new QStringListModel(items,this);//添加数据到QStringListModel集合

    model = new QStandardItemModel(5,3,this);

    QStringList V_Name;
    V_Name<<"LSY"<<"RHZ"<<"ZY"<<"NXY"<<"ZML";

    QStringList V_Addr;
    V_Addr<<"<qt>Da he tun zhen<br/>Fen dui wang cun wei</qt>"
          <<"Da he tun zhen <br/>xiao quan zhuang"
          <<"Bi dian zhen <br/>kong zhuang"
          <<"Shao bai si zhen <br/>dong gang cun "
          <<"Da he tun zhen <br/>jie bian";

    QStringList Types ;
    Types<< "0" << "1" << "2" << "0" << "2";
    for(int row=0 ;row < 5 ; ++row )
    {
        QStandardItem *item = new QStandardItem(V_Name[row]);
        model->setItem(row,0,item);

        item = new QStandardItem(V_Addr[row]);
        model->setItem(row,1,item);

        item = new QStandardItem(Types[row]);
        model->setItem(row,2,item);
    }


}

void ComboxWidgetMapper::UpdateButtons(int btn)
{
    Btn_Previous->setEnabled(btn > 0);

    Btn_Next->setEnabled(btn < model->rowCount() - 1 );
}
