#ifndef QADI_H
#define QADI_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>


class QAdi: public QGraphicsItem
{
public:
    QAdi();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void canvasReplot(void);

protected slots:
    void canvasReplot_slot(void);

protected:
    int     m_sizeMin, m_sizeMax;           ///< widget's min/max size (in pixel)
    int     m_size, m_offset;               ///< current size & offset

    double  m_roll;                         ///< roll angle (in degree)
    double  m_pitch;                        ///< pitch angle (in degree)

};

#endif // QADI_H
