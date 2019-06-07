#include "datarw.h"

DataRW::DataRW(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("QDataStream文件读取"));
    setMinimumSize(200,100);
    CreateUi();
}

DataRW::~DataRW()
{

}

void DataRW::CreateUi()
{
    label1 = new QLabel(tr("信道："));
    label2 = new QLabel(tr("功率："));
    label3 = new QLabel(tr("频率："));
    label4 = new QLabel(tr("MHz"));
    label5 = new QLabel(tr("上次保存于："));
    timeLabel = new QLabel("2012-02-14");

    SaveButton = new QPushButton(tr("保存"));
    connect(SaveButton,SIGNAL(clicked()),this,SLOT(SaveData()));
    GetButton = new QPushButton(tr("读取"));
    connect(GetButton,SIGNAL(clicked()),this,SLOT(GetData()));

    PowerComboBox = new QComboBox;

    QString str[3]={tr("高"),tr("中"),tr("低")};
    for(int i=0 ; i<3; i++)
    {
        PowerComboBox->addItem(str[i]);
    }
    ChangeSpinBox = new QSpinBox;
    frequencyEdit = new QLineEdit;

    QGridLayout *Main = new QGridLayout;
    //第一行
    Main->addWidget(label1,0,0,1,1);
    Main->addWidget(ChangeSpinBox,0,1,1,1);
    Main->addWidget(label5,0,2,1,1);
    Main->addWidget(timeLabel,0,3,1,1);

    //第二行
    Main->addWidget(label2,1,0,1,1);
    Main->addWidget(PowerComboBox,1,1,1,1);
    Main->addWidget(SaveButton,1,3,1,1);

    //第三行
    Main->addWidget(label3,2,0,1,1);
    Main->addWidget(frequencyEdit,2,1,1,1);
    Main->addWidget(label4,2,2,1,1);
    Main->addWidget(GetButton,2,3,1,1);

    setLayout(Main);
}

void DataRW::GetData()
{
    QFile file("para.dat");
    file.open(QIODevice::ReadOnly);

    QDataStream in(&file);

    //设置版本号
    in.setVersion(QDataStream::Qt_4_0);

   /* qint32 magic;

    in >> magic;
    if(magic != 0xa1a2a3a4)
    {
        QMessageBox::information(this,tr("提示"),tr("文件格式错误！"));
        return ;
    }*/
    qint32 channel;
    qint32 power;
    float frequency ;
    QDateTime time;
    in >> channel >> power >> frequency >>time;

    ChangeSpinBox->setValue(channel);
    PowerComboBox->setCurrentIndex(power);
    QString freq;
    frequencyEdit->setText(freq.setNum(frequency));

    QString lastTime = time.date().toString(Qt::ISODate) + " " + time.time().toString();
    timeLabel->setText(lastTime);


}
void DataRW::SaveData()
{
    int SpinBoxData = ChangeSpinBox->value();
    int ComboBoxIndex = PowerComboBox->currentIndex();
    float frequency = frequencyEdit->text().toFloat();

    QDateTime *time = new QDateTime;

    QFile file("para.dat");
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_0);

    //写入开头，可有可无
    //out << (quint32)0xa1a2a3a4;

    //写如int数据类型时最好转换为qt的数据类型，因为基本的C++数据类型在不同的平台上字节长度不同。推荐这种写法：
    out<< (quint32)SpinBoxData << (quint32)ComboBoxIndex << frequency <<time->currentDateTime();
    //不推荐这种写法
    //out<< SpinBoxData << ComboBoxIndex << frequency <<time->currentDateTime();


    QMessageBox::information(this,tr("提示"),tr("文件存档成功！"));

}
