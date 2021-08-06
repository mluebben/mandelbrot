#include "stdpch.h"
#include "mandelbrotview.h"
#include "mandelbrotrenderer.h"


MandelbrotView::MandelbrotView(QWidget *parent) : QWidget(parent)
{
    _image.fill(qRgb(127, 127, 127));

    _limit = 1000;
    _xMin = -2.0;
    _xMax = 2.0;
    _yMin = -2.0;
    _yMax = 2.0;
}


void MandelbrotView::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resizeEvent: " << event->size();

    _image = render(event->size());
}


void MandelbrotView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    qDebug() << "paintEvent";

    QPainter painter(this);
    //painter.setPen(Qt::blue);
    //painter.setFont(QFont("Arial", 30));
    //painter.drawText(rect(), Qt::AlignCenter, "Ich liebe dich!");


    painter.drawImage(0, 0, _image);
}


QImage MandelbrotView::render(QSize size)
{
    MandelbrotRenderer renderer;

    return renderer.render(size, _xMin, _xMax, _yMin, _yMax, _limit);
}
