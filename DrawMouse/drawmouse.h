#ifndef DRAWMOUSE_H
#define DRAWMOUSE_H

#include <QtGui>

class MyMouse : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(qreal turn READ ReadTurn WRITE SetTurn)

public:
    MyMouse(QGraphicsItem * parent = 0);
    ~MyMouse();

    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
    QRectF boundingRect () const;

    qreal ReadTurn()
    {
        return m_turn;
    }
    void SetTurn(qreal turn)
    {
        m_turn = turn;
    }
private slots:
    void ChangedColor();

private:
    qreal mouseEyeDirection;
    QTimer timer;
    QColor color;
    qreal m_turn;
};

#endif // DRAWMOUSE_H
