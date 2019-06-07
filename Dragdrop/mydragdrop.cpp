#include "mydragdrop.h"

Mydragdrop::Mydragdrop( QWidget * parent)
    : QFrame(parent)
{
    setMinimumSize(200,200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);

    //设置此窗体可接受拖拽事件
    setAcceptDrops(true);

    QLabel *boatLabel = new QLabel(this);
    boatLabel->setPixmap(QPixmap(":/images/boat.png"));
    boatLabel->move(10,10);
    boatLabel->show();

    //关闭label时， 删除该对象
    boatLabel->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *carLabel = new QLabel(this);
    carLabel->setPixmap(QPixmap(":/images/car.png"));
    carLabel->move(100,10);
    carLabel->show();

    carLabel->setAttribute(Qt::WA_DeleteOnClose);

    QLabel *houseLabel = new QLabel(this);
    houseLabel->setPixmap(QPixmap(":/images/house.png"));
    houseLabel->move(10,80);
    houseLabel->show();

    houseLabel->setAttribute(Qt::WA_DeleteOnClose);


}

Mydragdrop::~Mydragdrop()
{

}
//鼠标进入该控件并按下时调用该函数
void Mydragdrop::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug()<< " dragEnterEvent";
    if( event->mimeData()->hasFormat("Picture") )
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();;
        }else
        {
            event->acceptProposedAction();//推荐的处理方法
        }
    }else
        event->ignore();
}

//鼠标按下该控件并且移动时调用该函数
void Mydragdrop::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug()<< " dragMoveEvent";
    if( event->mimeData()->hasFormat("Picture") )
    {
        if(event->source() == this)
        {
            //设置drop的动作
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }else
        {
            //推荐的动作
            event->acceptProposedAction();
        }
    }else
        event->ignore();
}

//鼠标松开当前按下的控件时调用该函数
void Mydragdrop::dropEvent(QDropEvent *event)
{
    qDebug()<< " dropEvent";
    if(event->mimeData()->hasFormat("Picture"))
    {
        //获取二进制数据
        QByteArray data = event->mimeData()->data("Picture");

        //创建QDataStream操作该数据
        QDataStream stream(&data , QIODevice::ReadOnly);

        QPixmap pix;
        QPoint offset;

        //读取图片和偏移量
        stream >> pix >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pix);
        newIcon->move(event->pos() - offset);
        newIcon->show();

        if(event->source() == this)
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
void Mydragdrop::mousePressEvent(QMouseEvent *event)
{
    qDebug()<< " mousePressEvent";
    //获取在鼠标点击处的Widget
    QLabel *child = static_cast<QLabel *> (childAt(event->pos()));
    qDebug()<<"RHZ";
    if( !child )
        return ;
    qDebug()<<"LSY";

    //获取该Widget上的图片
    QPixmap pixmap = *child->pixmap();

    QByteArray bytearray;
    QDataStream dataStream(&bytearray,QIODevice::WriteOnly);

    //保存图片和偏移量
   // dataStream << pixmap << QPointer(event->pos() - child->pos() );
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    //设置mime数据
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("Picture", bytearray);

    //生成一个可拖拽的对象
    QDrag *drag = new QDrag(this) ;

    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    //设置拖动鼠标时相对于拖拽图标左上角的位置
    drag->setHotSpot(event->pos() - child->pos());

    QPixmap tempImg = pixmap;
    QPainter painter;
    painter.begin(&tempImg);
    //给被拖拽对象添加一层半透明颜色
    painter.fillRect(tempImg.rect() , QColor(127,127,127,127));
    painter.end();

    child->setPixmap(tempImg);


    /*
    拖曳的动作有

    Qt::CopyAction
    Qt::MoveAction
    Qt::LinkAction
    Qt::ActionMask
    Qt::IgnoreAction
    Qt::TargetMoveAction

    */
    //进入拖拽循环   可能的返回值                     ，  缺省的返回值
    if(drag->exec(Qt::CopyAction | Qt::MoveAction , Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else
    {
        child->show();
        child->setPixmap(pixmap);
    }
}
