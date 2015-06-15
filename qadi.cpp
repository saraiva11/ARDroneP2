#include "qadi.h"
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

QAdi::QAdi()
{
    m_sizeMin = 200;
    m_sizeMax = 600;
    m_offset = 2;
    m_size = 250;

   //setMinimumSize(m_sizeMin, m_sizeMin);
   //setMaximumSize(m_sizeMax, m_sizeMax);
   //resize(m_sizeMin, m_sizeMin);

   //setFocusPolicy(Qt::NoFocus);

   m_roll  = 0.0;
   m_pitch = 0.0;
}

QRectF QAdi::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void QAdi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush bgSky(QColor(48,172,220));
    QBrush bgGround(QColor(247,168,21));

    QPen   whitePen(Qt::white);
    QPen   blackPen(Qt::black);
    QPen   pitchPen(Qt::white);
    QPen   pitchZero(Qt::green);

    whitePen.setWidth(2);
    blackPen.setWidth(2);
    pitchZero.setWidth(3);

    painter->setRenderHint(QPainter::Antialiasing);

    /*Referenial no centro da circunferencia*/
    painter->translate(125,125);


    // FIXME: AHRS output left-hand values
        double pitch_tem = -m_pitch;

    // draw background
    {
        int y_min, y_max;

         y_min = m_size/2*-40.0/45.0;
         y_max = m_size/2* 40.0/45.0;

         int y = m_size/2*pitch_tem/45.;
         if( y < y_min ) y = y_min;
         if( y > y_max ) y = y_max;

         int x = sqrt(m_size*m_size/4 - y*y);
         qreal gr = atan((double)(y)/x);
         gr = gr * 180./3.1415926;

         painter->setPen(blackPen);
         painter->setBrush(bgSky);
         painter->drawChord(-m_size/2, -m_size/2, m_size, m_size,gr*16, (180-2*gr)*16);

         painter->setBrush(bgGround);
         painter->drawChord(-m_size/2, -m_size/2, m_size, m_size,gr*16, -(180+2*gr)*16);
     }

     // set mask
     QRegion maskRegion(-m_size/2, -m_size/2, m_size, m_size, QRegion::Ellipse);
     painter->setClipRegion(maskRegion);

     // draw pitch lines & marker
     {
             int x, y, x1, y1;
             int textWidth;
             double p, r;
             int ll = m_size/8, l;

             int     fontSize = 8;
             QString s;

             pitchPen.setWidth(2);
             painter->setFont(QFont("", fontSize));


             // draw lines
             for(int i=-9; i<=9; i++) {
                 p = i*10;

                 s = QString("%1").arg(-p);

                 if( i % 3 == 0 )
                     l = ll;
                 else
                     l = ll/2;

                 if( i == 0 ) {
                     painter->setPen(pitchZero);
                     l = l * 1.8;
                 } else {
                     painter->setPen(pitchPen);
                 }

                 y = m_size/2*p/45.0 - m_size/2*pitch_tem/45.;
                 x = l;

                 r = sqrt(x*x + y*y);
                 if( r > m_size/2 ) continue;

                 painter->drawLine(QPointF(-l, 1.0*y), QPointF(l, 1.0*y));

                 textWidth = 100;

                 if( i % 3 == 0 && i != 0 ) {
                     painter->setPen(QPen(Qt::white));

                     x1 = -x-2-textWidth;
                     y1 = y - fontSize/2 - 1;
                     painter->drawText(QRectF(x1, y1, textWidth, fontSize+2),
                                      Qt::AlignRight|Qt::AlignVCenter, s);
                 }
             }

             // draw marker
                     int     markerSize = m_size/20;
                     float   fx1, fy1, fx2, fy2, fx3, fy3;

                     painter->setBrush(QBrush(Qt::red));
                     painter->setPen(Qt::NoPen);

                     fx1 = markerSize;
                     fy1 = 0;
                     fx2 = fx1 + markerSize;
                     fy2 = -markerSize/2;
                     fx3 = fx1 + markerSize;
                     fy3 = markerSize/2;

                     QPointF points[3] = {
                         QPointF(fx1, fy1),
                         QPointF(fx2, fy2),
                         QPointF(fx3, fy3)
                     };
                     painter->drawPolygon(points, 3);

                     QPointF points2[3] = {
                         QPointF(-fx1, fy1),
                         QPointF(-fx2, fy2),
                         QPointF(-fx3, fy3)
                     };
                     painter->drawPolygon(points2, 3);
    }

     // draw roll degree lines
         {
             int     nRollLines = 36;
             float   rotAng = 360.0 / nRollLines;
             int     rollLineLeng = m_size/25;
             double  fx1, fy1, fx2, fy2;
             int     fontSize = 8;
             QString s;

             blackPen.setWidth(1);
             painter->setPen(blackPen);
             painter->setFont(QFont("", fontSize));

             for(int i=0; i<nRollLines; i++) {
                 if( i < nRollLines/2 )
                     s = QString("%1").arg(-i*rotAng);
                 else
                     s = QString("%1").arg(360-i*rotAng);

                 fx1 = 0;
                 fy1 = -m_size/2 + m_offset;
                 fx2 = 0;

                 if( i % 3 == 0 ) {
                     fy2 = fy1 + rollLineLeng;
                     painter->drawLine(QPointF(fx1, fy1), QPointF(fx2, fy2));

                     fy2 = fy1 + rollLineLeng+2;
                     painter->drawText(QRectF(-50, fy2, 100, fontSize+2),
                                      Qt::AlignCenter, s);
                 } else {
                     fy2 = fy1 + rollLineLeng/2;
                     painter->drawLine(QPointF(fx1, fy1), QPointF(fx2, fy2));
                 }

                 painter->rotate(-rotAng);
             }
         }
     // draw roll marker
         {
             int     rollMarkerSize = m_size/25;
             double  fx1, fy1, fx2, fy2, fx3, fy3;

             painter->rotate(-m_roll);
             painter->setBrush(QBrush(Qt::black));

             fx1 = 0;
             fy1 = -m_size/2 + m_offset;
             fx2 = fx1 - rollMarkerSize/2;
             fy2 = fy1 + rollMarkerSize;
             fx3 = fx1 + rollMarkerSize/2;
             fy3 = fy1 + rollMarkerSize;

             QPointF points[3] = {
                 QPointF(fx1, fy1),
                 QPointF(fx2, fy2),
                 QPointF(fx3, fy3)
             };
             painter->drawPolygon(points, 3);
         }
}

