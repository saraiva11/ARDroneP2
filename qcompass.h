#ifndef QCOMPASS_H
#include <QtCore>
#include <QtGui>
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>


class QCompass : public QGraphicsItem
{
public:
    QCompass();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /*Set Fuctions*/
    void setData(double y, double a, double h);
    void setYaw(double val);
    void setAlt(double val);
    void setH(double val);

    /*Get Fuctions*/
    double getYaw();
    double getAlt();
    double getH();

signals:
    void canvasReplot(void);

protected slots:
    void canvasReplot_slot(void);


protected:
    int     m_sizeMin, m_sizeMax;               ///< widget min/max size (in pixel)
    int     m_size, m_offset;                   ///< widget size and offset size

    double  m_yaw;                              ///< yaw angle (in degree)
    double  m_alt;                              ///< altitude (in m)
    double  m_h;                                ///< height from ground (in m

private:
    //void drawAltitude(void);
    //void drawAltitude(QPainter **painter);
};

#endif // QCOMPASS_H
