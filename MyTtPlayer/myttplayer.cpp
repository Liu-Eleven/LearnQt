#include "myttplayer.h"

MyTtPlayer::MyTtPlayer(QWidget *parent)
    : QWidget(parent)
{
    setMaximumWidth(240);
    CreateTTPlayerUi();
}

MyTtPlayer::~MyTtPlayer()
{

}

void MyTtPlayer::CreateTTPlayerUi()
{
    L_lrcServ = new QLabel(tr("Lyric Server:"));//歌词服务器
    L_Sur = new QLabel(tr("Surrogate set"));//surrogate//代理设置
    L_Chanier = new QLabel(tr("Chansonnier:"));//chansonnier：歌手
    L_Chan = new QLabel(tr("Chanson:"));//chanson：歌名

    Btn_ferret = new QPushButton(tr("Ferret"));//ferret:搜索
    Cbo_Serv = new QComboBox;//歌词服务器
    Cbo_Serv->addItem(tr("Lyric Server(meshwork connect)"));//歌词服务（网通）
    Cbo_Serv->addItem(tr("Lyric Server(Telecommunication)"));//歌词服务（电信）

    Edit_Chanier = new QLineEdit;
    Edit_Chan = new QLineEdit;

    QGridLayout *layout1 = new QGridLayout ;

    layout1->addWidget(L_lrcServ,0,0,1,1);
    layout1->addWidget(Cbo_Serv,0,1,1,3);
    layout1->addWidget(L_Sur,0,4,1,1);

    layout1->addWidget(L_Chanier,1,0,1,1);
    layout1->addWidget(Edit_Chanier,1,1,1,1);
    layout1->addWidget(L_Chan,1,2,1,1);
    layout1->addWidget(Edit_Chan,1,3,1,1);
    layout1->addWidget(Btn_ferret,1,4,1,1);

    //初始化第二个布局
    TwoGroup = new QGroupBox(tr("Choose the lyrics document that search carries on a download:"));
    TreeView = new QTreeView;

    QStandardItemModel *model = new QStandardItemModel(0,2,this);

    model->setHeaderData(0,Qt::Horizontal,tr("chansonnier"));
    model->setHeaderData(1,Qt::Horizontal,tr("chanson"));

    model->insertRow(0);
    model->setData(model->index(0,0),tr("unknow"));
    model->setData(model->index(0,1),tr("because of you"));
    TreeView->setModel(model);
    QVBoxLayout *layout2 = new QVBoxLayout ;
    layout2->addWidget(TreeView);
    TwoGroup->setLayout(layout2);

    //初始化最后一个布局
    L_Save = new QLabel(tr("Save as:"));//保存为
    Ck_Un = new QCheckBox(tr("Carry on"));//下载后与歌曲文件进行关联 a connection with song document after downloading

    Btn_DownLoad = new QPushButton(tr("download"));
    Btn_Close = new QPushButton(tr("Close"));
    Edit_Save = new QLineEdit;
    QGridLayout *layout3 = new QGridLayout ;
    layout3->addWidget(L_Save,0,0,1,1);
    layout3->addWidget(Edit_Save,0,1,1,3);

    layout3->addWidget(Ck_Un,1,0,1,2);
    layout3->addWidget(Btn_DownLoad,1,2,1,1);
    layout3->addWidget(Btn_Close,1,3,1,1);


    mainLayout = new QVBoxLayout ;
    mainLayout->addLayout(layout1);
    mainLayout->addWidget(TwoGroup);
    mainLayout->addLayout(layout3);
    setLayout(mainLayout);
}
