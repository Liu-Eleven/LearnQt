#include "draglabel.h"

DragLabel::DragLabel( const QString &text , QWidget * parent) :
    QLabel(text , parent)
{
    //设置背景是否自动填充
    setAutoFillBackground(true);
    /*
    QFame属性frameShape : Shape

    QFrame::NoFrame
    QFrame::Box
    QFrame::Panel
    QFrame::StyledPanel
    QFrame::HLine
    QFrame::VLine
    QFrame::WinPanel
    */
    setFrameShape(QFrame::Panel);
    /*
    QFame属性frameShadow : Shadow

    QFrame::Plain
    QFrame::Raised
    QFrame::Sunken
    */
    setFrameShadow(QFrame::Raised);
}
DragLabel::~DragLabel()
{
}
void DragLabel::mousePressEvent(QMouseEvent *event)
{
    QString str = text();
    QPixmap pix;
    //调用grabWidget把标签作为图片获取
    pix = pix.grabWidget(this);

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    stream << str << QPoint(event->pos() - rect().topLeft() );
    //创建QMimeDate对象，保存拖拽数据
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("Drag-Text",data);
    mimeData->setText(str);

    //创建拖拽对象
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pix);
    drag->setHotSpot(QPoint(event->pos() - rect().topLeft() ));

    hide();

    Qt::DropAction DragAction = drag->start(Qt::CopyAction | Qt::MoveAction) ;

    if(DragAction == Qt::MoveAction )
        close();
    else
        show();
}
