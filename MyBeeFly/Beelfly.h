#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>

class Beelfly : public QGraphicsObject//等同与...public QObject , public QGraphicsItem
{
    Q_OBJECT
  //  Q_PROPERTY(qreal turn READ ReadTurn WRITE setTurn)
   //  Q_PROPERTY(qreal turn READ ReadTurn WRITE SetTurn)

public:
    Beelfly( QGraphicsItem * parent = 0 );
    ~Beelfly();

    void timerEvent(QTimerEvent *);
    QRectF boundingRect() const;

   /* qreal ReadTurn()
    {
        return m_turn ;
    }

    void SetTurn(qreal turn)
    {
        m_turn = turn ;
    }*/

protected:
    void paint(QPainter *painter , const QStyleOptionGraphicsItem *option , QWidget *widget);

private slots:
    void ChangedTurn();

private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;


    qreal angle;
    qreal m_turn ;

    QTimer timer;

};

#endif // WIDGET_H
