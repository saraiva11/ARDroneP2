#include "qcompass.h"

QCompass::QCompass()
{
    //Pressed = false;
    //this->setFlag(ItemIsMovable);




    m_sizeMin = 200;
    m_sizeMax = 600;
    m_offset = 2;
    m_size = m_sizeMin - 2*m_offset;



    //this->setMinimumSize(m_sizeMin, m_sizeMin);
    //this->setMaximumSize(m_sizeMax, m_sizeMax);
    //this->resize(m_sizeMin, m_sizeMin);

    //this->setFocusPolicy(Qt::NoFocus);

    m_yaw  = 0.0;
    m_alt  = 0.0;
    m_h    = 0.0;
}

QRectF QCompass::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void QCompass::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QPainter painter(this);

    QBrush bgGround(QColor(48,172,220));

    QPen   whitePen(Qt::white);
    QPen   blackPen(Qt::black);
    QPen   redPen(Qt::red);
    QPen   bluePen(Qt::blue);
    QPen   greenPen(Qt::green);

    whitePen.setWidth(1);
    blackPen.setWidth(2);
    redPen.setWidth(2);
    bluePen.setWidth(2);
    greenPen.setWidth(2);

    painter->setRenderHint(QPainter::Antialiasing);

    /*Referenial no centro da circunferencia*/
    painter->translate(125,125);


    //Desenhar backgroud
    painter->setPen(blackPen);
    painter->setBrush(bgGround);

    //painter->drawEllipse(-m_size/2, -m_size/2, m_size, m_size);
    //painter->drawLine(QPoint(125,0),QPoint(125,250));
    painter->drawEllipse(QPoint(0,0),125,125);




    //painter->drawPoint(125,125);

    //draw yaw lines
    int     nyawLines = 36;
    float   rotAng = 360.0 / nyawLines;
    int     yawLineLeng = m_size/25;
    double  fx1, fy1, fx2, fy2;
    int     fontSize = 8;
    QString s;

    blackPen.setWidth(1);
    painter->setPen(blackPen);

    for(int i=0; i<nyawLines; i++)
    {
        if( i == 0 ) {
            s = "N";
            painter->setPen(bluePen);

            painter->setFont(QFont("", fontSize*1.3));
        } else if ( i == 9 ) {
            s = "E";
            painter->setPen(blackPen);

            painter->setFont(QFont("", fontSize*1.3));
        } else if ( i == 18 ) {
            s = "S";
            painter->setPen(redPen);

            painter->setFont(QFont("", fontSize*1.3));
        } else if ( i == 27 ) {
            s = "W";
            painter->setPen(blackPen);

            painter->setFont(QFont("", fontSize*1.3));
        } else {
            s = QString("%1").arg(i*rotAng);
            painter->setPen(blackPen);

            painter->setFont(QFont("", fontSize));

        }

        fx1 = 0;
        fy1 = -125;
        fx2 = 0;

        //Míltiplos de 3
        if(i % 3 == 0)
        {
            fy2 = fy1+10;
            painter->drawLine(QPointF(fx1,fy1),QPointF(fx2,fy2));

            fy2 = fy1+12;
            painter->drawText(QRectF(-50, fy2, 100, fontSize+2),Qt::AlignCenter, s);

        }
        else
        {
            fy2 = fy1 + 5;
            painter->drawLine(QPointF(fx1, fy1), QPointF(fx2, fy2));
        }
        painter->rotate(rotAng);
    }

    //draw S/N arrow
    {
        int     arrowWidth = 250/5;
        double  fx1, fy1, fx2, fy2, fx3, fy3;

        fx1 = 0;
        fy1 = -125 +250/25 + 15;
        fx2 = -arrowWidth/2;
        fy2 = 0;
        fx3 = arrowWidth/2;
        fy3 = 0;

        painter->setPen(Qt::NoPen);

        painter->setBrush(QBrush(Qt::blue));
        QPointF pointsN[3] = {
           QPointF(fx1, fy1),
           QPointF(fx2, fy2),
           QPointF(fx3, fy3)
        };

        painter->drawPolygon(pointsN, 3);

        fx1 = 0;
        fy1 = 125 - 250/25 - 15;
        fx2 = -arrowWidth/2;
        fy2 = 0;
        fx3 = arrowWidth/2;
        fy3 = 0;

        painter->setBrush(QBrush(Qt::red));
        QPointF pointsS[3] = {
           QPointF(fx1, fy1),
           QPointF(fx2, fy2),
           QPointF(fx3, fy3)
        };

        painter->drawPolygon(pointsS, 3);
    }

    // draw yaw marker
        {
            int     yawMarkerSize = 250/12;
            double  fx1, fy1, fx2, fy2, fx3, fy3;

            painter->rotate(-m_yaw);
            painter->setBrush(QBrush(QColor(0xFF, 0x00, 0x00, 0xE0)));

            fx1 = 0;
            fy1 = -250/2;
            fx2 = fx1 - yawMarkerSize/2;
            fy2 = fy1 + yawMarkerSize;
            fx3 = fx1 + yawMarkerSize/2;
            fy3 = fy1 + yawMarkerSize;

            QPointF points[3] = {
                QPointF(fx1, fy1),
                QPointF(fx2, fy2),
                QPointF(fx3, fy3)
            };
            painter->drawPolygon(points, 3);

            painter->rotate(m_yaw);
        }

    // draw altitude
        {
            int     altFontSize = 13;
            int     fx, fy, w, h;
            QString s;
            char    buf[200];

            w  = 130;
            h  = (altFontSize + 14);
            fx = -w/2;
            fy = -h/2;

            blackPen.setWidth(2);
            painter->setPen(blackPen);
            painter->setBrush(QBrush(Qt::white));
            painter->setFont(QFont("", altFontSize));

            painter->drawRoundedRect(fx, fy, w, h, 6, 6);

            painter->setPen(bluePen);
            sprintf(buf, "ALT: %6.1f m", m_alt);
            s = buf;
            painter->drawText(QRectF(fx, fy+2, w, h/2), Qt::AlignCenter, s);

            //sprintf(buf, "H: %6.1f m", m_h);
            //s = buf;
            //painter->drawText(QRectF(fx, fy+h/2, w, h/2), Qt::AlignCenter, s);
        }

}

void QCompass::setData(double y, double a, double h)
{
    m_yaw = y;
    m_alt = a;
    m_h   = h;

    if( m_yaw < 0   ) m_yaw = 360 + m_yaw;
    if( m_yaw > 360 ) m_yaw = m_yaw - 360;

    //emit canvasReplot();
}

void QCompass::setAlt(double val)
{
    m_alt = val;
    //emit canvasReplot();
}

void QCompass::setYaw(double val)
{
    m_yaw  = val;
    if( m_yaw < 0   ) m_yaw = 360 + m_yaw;
    if( m_yaw > 360 ) m_yaw = m_yaw - 360;

    //emit canvasReplot();
}

void QCompass::setH(double val)
{
    m_h = val;

    //emit canvasReplot();
}

/*void QCompass::drawYawMarker()
{
}*/

void QCompass::canvasReplot_slot()
{
    update();
}

/*void QCompass::drawAltitude(QPainter **painter)
{

}*/



