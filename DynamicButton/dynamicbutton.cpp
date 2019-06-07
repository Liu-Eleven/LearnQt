#include "dynamicbutton.h"

DynamicButton::DynamicButton( QWidget * parent, Qt::WindowFlags f)
    : QDialog(parent,f)
{
    QFont font("ZYSong18030",12);
    setFont(font);

    setWindowTitle(tr("Event Filter"));

    labelState = new QLabel(tr("all"));

    image1.load("./images/0.jpg");
    image2.load("./images/1.jpg");
    image3.load("./images/2.jpg");


    label11 = new QLabel;
    QMatrix martix;
    martix.scale(0.5,0.5);
    QImage tmp = image1.transformed(martix);
    label11->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
     /* label11->setSizePolicy(QSizePolicy::Ignored , QSizePolicy::Ignored);
    label11->setScaledContents(true);*/
    label11->setPixmap(QPixmap::fromImage(tmp));


    label2 = new QLabel;
    tmp = image2.transformed(martix);
    label2->setPixmap(QPixmap::fromImage(tmp));


    label3 = new QLabel;
    tmp = image3.transformed(martix);
    label3->setPixmap(QPixmap::fromImage(tmp));


    QGridLayout *layout = new QGridLayout;

    layout->addWidget(label11,0,0,1,1);
    layout->addWidget(label2,0,1,1,1);
    layout->addWidget(label3,0,2,1,1);
    layout->addWidget(labelState,1,0,1,3);
    this->setLayout(layout);

    label11->installEventFilter(this);
    label2->installEventFilter(this);
    label3->installEventFilter(this);
}

DynamicButton::~DynamicButton()
{

}

bool DynamicButton::eventFilter(QObject *watched, QEvent *event)
{


    if(watched == label11)
    {
        if( event->type() == QEvent::MouseButtonPress || event->type() == QEvent::Enter )
        {
            qDebug()<<"lsy1";
            QMouseEvent *mouseEvent = (QMouseEvent *)event;
            QMatrix martix;
            martix.scale(0.8,0.8);
            QImage tmp = image1.transformed(martix);
            label11->setPixmap(QPixmap::fromImage(tmp));

            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                labelState->setText(tr("Left mouse button pressed on left image"));
            }else if(mouseEvent->buttons() & Qt::MidButton )
            {
                labelState->setText(tr("Middle mouse button pressed left image"));
            }else if(mouseEvent->buttons() & Qt::RightButton)
            {
                labelState->setText(tr("Right mouse button pressed on left image"));

            }
        }

        if(event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave)
        {
            qDebug()<<"release";
            labelState->setText(tr("Mouse button released from left image"));
            QMatrix martix;
            martix.scale(0.5,0.5);
            QImage tmp = image1.transformed(martix);
            label11->setPixmap(QPixmap::fromImage(tmp));
        }

    }

    if(watched == label2 )
    {

        if( event->type() == QEvent::MouseButtonPress  || event->type() == QEvent::Enter)
        {
            qDebug()<<"lsy2";
            QMouseEvent *mouseEvent = (QMouseEvent *)event;

            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                labelState->setText(tr("left mouse button pressed on left image"));
            }else if(mouseEvent->buttons() & Qt::MidButton )
            {
                labelState->setText(tr("Middle mouse button pressed left image"));
            }else if(mouseEvent->buttons() & Qt::RightButton)
            {
                labelState->setText(tr("Right mouse button pressed on left image"));

            }

            QMatrix martix;
            martix.scale(0.8,0.8);

            QImage tmp = image2.transformed(martix);
            label2->setPixmap(QPixmap::fromImage(tmp));
        }

        if(event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave)
        {
            labelState->setText(tr("Mouse button released from left image"));
            QMatrix martix;
            martix.scale(0.5,0.5);
            QImage tmp = image2.transformed(martix);
            label2->setPixmap(QPixmap::fromImage(tmp));
        }
    }


    if(watched == label3)
    {


        if( event->type() == QEvent::MouseButtonPress  || event->type() == QEvent::Enter)
        {
            qDebug()<<"lsy3";
            QMouseEvent *mouseEvent = (QMouseEvent *)event;

            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                labelState->setText(tr("Left mouse button pressed on left image"));
            }else if(mouseEvent->buttons() & Qt::MidButton )
            {
                labelState->setText(tr("Middle mouse button pressed left image"));
            }else if(mouseEvent->buttons() & Qt::RightButton)
            {
                labelState->setText(tr("Right mouse button pressed on left image"));

            }

            QMatrix martix;
            martix.scale(0.8,0.8);

            QImage tmp = image3.transformed(martix);
            label3->setPixmap(QPixmap::fromImage(tmp));
        }

        if(event->type() == QEvent::MouseButtonRelease || event->type() == QEvent::Leave)
        {
            labelState->setText(tr("Mouse button released from left image"));
            QMatrix martix;
            martix.scale(0.5,0.5);
            QImage tmp = image3.transformed(martix);
            label3->setPixmap(QPixmap::fromImage(tmp));
        }
    }
    return QDialog::eventFilter( watched, event);
}
