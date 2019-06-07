#include "qqdialog.h"

QQDialog::QQDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("QQ info");
    CreateUi();
}

QQDialog::~QQDialog()
{

}

void QQDialog::CreateUi()
{
    label1 = new QLabel(tr("UserName:"));
    label2 = new QLabel(tr("Name:    "));
    label3 = new QLabel(tr("Gender:  "));
    label4 = new QLabel(tr("Departmen:"));
    label5 = new QLabel(tr("Age:     "));
    label6 = new QLabel(tr("BAK:     "));
    label7 = new QLabel(tr("Picture:"));
    MyOther = new QLabel(tr("show:"));
    MyIcon = new QLabel("ICON");

    LineEditUser = new QLineEdit;
    LineEditName = new QLineEdit;
    LineEditAge = new QLineEdit;
    LineEditBak = new QLineEdit;

    comboBoxSex = new QComboBox;
    comboBoxSex->addItem(tr("BOY"));
    comboBoxSex->addItem(tr("GIRL"));

    textEditDepartment = new QTextEdit;
    textEditDisc = new QTextEdit;

    pushButtonIcon = new QPushButton(tr("Update"));
    connect(pushButtonIcon,SIGNAL(clicked()),this,SLOT(OpenFile()));
    pushButtonOk = new QPushButton(tr("OK"));
    pushButtonExit = new QPushButton(tr("Cancel"));

//左边布局
    QGridLayout *LeftLayout = new QGridLayout;
    LeftLayout->addWidget(label1,0,0,1,1);
    LeftLayout->addWidget(LineEditUser,0,1,1,1);
    LeftLayout->addWidget(label2,1,0,1,1);
    LeftLayout->addWidget(LineEditName,1,1,1,1);
    LeftLayout->addWidget(label3,2,0,1,1);
    LeftLayout->addWidget(comboBoxSex,2,1,1,1);
    QHBoxLayout *hb0 = new QHBoxLayout;
    QVBoxLayout *vb0 = new QVBoxLayout;
    vb0->addWidget(label4);
    vb0->addStretch();
    hb0->addLayout(vb0);
    hb0->addWidget(textEditDepartment);
    LeftLayout->addLayout(hb0,3,0,1,2);
    //LeftLayout->addWidget(label4,3,0,1,1);
    //LeftLayout->addWidget(textEditDepartment,3,1,1,4);
    LeftLayout->addWidget(label5,4,0,1,1);
    LeftLayout->addWidget(LineEditAge,4,1,1,1);  
    LeftLayout->addWidget(label6,5,0,1,1);
    LeftLayout->addWidget(LineEditBak,5,1,1,1);


    QVBoxLayout *rightLayout = new QVBoxLayout;
    QHBoxLayout *hb = new QHBoxLayout ;
    hb->addWidget(label7);
    hb->addWidget(MyIcon);
    hb->addWidget(pushButtonIcon);
    rightLayout->addLayout(hb);
    rightLayout->addWidget(MyOther);
    rightLayout->addWidget(textEditDisc);
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(pushButtonOk);
    bottomLayout->addWidget(pushButtonExit);



    QGridLayout *MainLayout = new QGridLayout;
    MainLayout->addLayout(LeftLayout,0,0,1,1);
    MainLayout->addLayout(rightLayout,0,1,1,1);
    MainLayout->addLayout(bottomLayout,1,0,1,2);

    setLayout(MainLayout);


}

bool QQDialog::OpenFile()
{

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),"",
                                                    tr("All Image(*)"));
    if( fileName.isEmpty() )
        return false;
    qDebug()<<fileName;
    MyIcon->setPixmap(QPixmap(fileName));

    return true;
}
