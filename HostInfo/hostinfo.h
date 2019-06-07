#ifndef HOSTINFO_H
#define HOSTINFO_H

#include <QtGui>
#include <QtNetwork>

class HostInfo : public QWidget
{
    Q_OBJECT

public:
    HostInfo( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    ~HostInfo();
private slots:
    void DetailsInfo();

private:
    QLineEdit *HostNameText;
    QLineEdit *HostIpText;

    QPushButton *DetailsBtn;

    QGridLayout *Mainlayout;

};

class DetailsHostInfo : public QWidget
{
public:

    DetailsHostInfo( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    ~DetailsHostInfo();
private:
    QLabel *DetailsLabel ;

};

#endif // HOSTINFO_H



