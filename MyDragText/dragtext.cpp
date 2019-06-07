#include "dragtext.h"

DragText::DragText(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("拖拽文字"));
    setMinimumSize(200,200);
    QLabel *label = new QLabel(tr("情人节"),this);

    int x,y;
    x = qrand()%200;
    y = qrand()%200;
    label->move(x,y);
    label->setAutoFillBackground(true);
    label->show();
    label->setAttribute(Qt::WA_DeleteOnClose);
    this->setAcceptDrops(true);
}

DragText::~DragText()
{

}

void DragText::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<tr("鼠标进入该控件并按下时调用该函数");
    if(event->mimeData()->hasText())
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
            event->acceptProposedAction();
    }else
        event->ignore();

}
void DragText::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<tr("鼠标点击此控件并且移动！");
    if(event->mimeData()->hasText())
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
            event->acceptProposedAction();
    }else
        event->ignore();
}
void DragText::dropEvent(QDropEvent *event)
{
    qDebug()<<tr("鼠标松开当前按下的控件时调用该函数");
    if(event->mimeData()->hasText())
    {
        QString text = event->mimeData()->text();
        QByteArray array = event->mimeData()->data("TextPos");
        QPoint point;
        QDataStream stream(&array,QIODevice::ReadOnly);
        stream >> point;

        QLabel *newLabel = new QLabel(text,this);
        newLabel->move(event->pos() - point);
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);

        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
            event->acceptProposedAction();
    }else
        event->ignore();
}
void DragText::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<tr("鼠标按下，调用此函数！");
    QLabel *child = static_cast<QLabel *>(childAt(event->pos()));
    if( !child )
        return;

    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);
    stream << QPoint(event->pos() - child->pos());
    QMimeData *mimeData = new QMimeData ;
    mimeData->setText(child->text());
    mimeData->setData("TextPos",array);

    QPixmap pix(child->size());
    //在pixmap上绘制child
    child->render(&pix);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pix);
    drag->setHotSpot(event->pos() - child->pos());
    //                           支持的动作              缺省的动作
    if( drag->exec(Qt::CopyAction | Qt::MoveAction , Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else
        child->show();
}
