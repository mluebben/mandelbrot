//#include <QPainter>

#include <QtGui>



#include "mandelbrotview.h"

MandelbrotView::MandelbrotView(QWidget *parent) : QWidget(parent)
{

    //_image = generateImage();

}


void MandelbrotView::resizeEvent(QResizeEvent *event)
{
    _image = generateImage(event->size());
    //update();



}


void MandelbrotView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Ich liebe dich!");


    painter.drawImage(0, 0, _image);
}



QImage MandelbrotView::generateImage(QSize size)
{
    QImage image(size.width(), size.height(), QImage::Format_RGB32);
    QRgb value;

    value = qRgb(189, 149, 39); // 0xffbd9527
    image.setPixel(1, 1, value);

    value = qRgb(122, 163, 39); // 0xff7aa327
    image.setPixel(0, 1, value);
    image.setPixel(1, 0, value);

    value = qRgb(237, 187, 51); // 0xffedba31
    image.setPixel(2, 1, value);

    return image;
}
