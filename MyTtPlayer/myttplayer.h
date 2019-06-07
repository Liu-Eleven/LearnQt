#ifndef MYTTPLAYER_H
#define MYTTPLAYER_H

#include <QtGui>

class MyTtPlayer : public QWidget
{
    Q_OBJECT

public:
    MyTtPlayer(QWidget *parent = 0);
    ~MyTtPlayer();

private:
    //第一个布局管理器：
    QLabel *L_lrcServ;//歌词服务器
    QLabel *L_Sur;//surrogate//代理设置
    QLabel *L_Chanier;//chansonnier：歌手
    QLabel *L_Chan;//chanson：歌名

    QPushButton *Btn_ferret;//ferret:搜索
    QComboBox *Cbo_Serv;//歌词服务器

    QLineEdit *Edit_Chanier;
    QLineEdit *Edit_Chan;

    QVBoxLayout *mainLayout;

    //第二个布局
    QGroupBox *TwoGroup;
    QTreeView *TreeView;

    //第三个布局
    QLabel *L_Save;//保存为
    QCheckBox *Ck_Un;//下载后与歌曲文件进行关联
    QLineEdit *Edit_Save;

    QPushButton *Btn_DownLoad;
    QPushButton *Btn_Close;


    void CreateTTPlayerUi();



};

#endif // MYTTPLAYER_H
