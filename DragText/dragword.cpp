#include "dragword.h"

DragWord::DragWord(QWidget * parent)
    : QFrame(parent)
{
    setMinimumSize(300,300);
    setAcceptDrops(true);
    setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
}

DragWord::~DragWord()
{

}

void DragWord::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<<"dragEnterEvent";
    if(event->mimeData()->hasText())
    {

        if( children().contains(event->source()) )
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
        {
            event->acceptProposedAction();
        }
    }else
        event->ignore();
}
void DragWord::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<<"dragMoveEvent";
    if(event->mimeData()->hasText())
    {

        if( children().contains(event->source()) )
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
        {
            event->acceptProposedAction();
        }
    }else
        event->ignore();
}
void DragWord::dropEvent(QDropEvent *event)
{
    qDebug()<<"dropEvent";
    if(event->mimeData()->hasFormat("Drag-Text"))
    {
        QByteArray data = event->mimeData()->data("Drag-Text");
        QDataStream stream(&data,QIODevice::ReadOnly);

        QString text;
        QPoint offset;
        stream >> text >> offset;

        DragLabel *newLabel = new DragLabel(text,this);
        newLabel->move(event->pos() - offset);
        newLabel->show();

        if( children().contains(event->source()) )
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
        {
            event->acceptProposedAction();
        }

    }else if(event->mimeData()->hasText())
    {
        QStringList strList = event->mimeData()->text().split(QRegExp("\\s+"),QString::SkipEmptyParts);
        QPoint pos = event->pos();
        foreach (QString str , strList)
        {
            DragLabel *dragLabel = new DragLabel(str, this);
            dragLabel->move(pos);
            dragLabel->show();
            pos += QPoint(dragLabel->width(),0);

        }

        if( children().contains(event->source()) )
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
        {
            event->acceptProposedAction();
        }
    }else
        event->ignore();
}
