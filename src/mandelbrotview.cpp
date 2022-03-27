// SPDX-License-Identifier: GPL-3.0-or-later
//
// Copyright 2022 Matthias Lübben <ml81@gmx.de>
//

#include "stdpch.h"
#include "mandelbrotview.h"
#include "mandelbrotrenderer.h"


MandelbrotView::MandelbrotView(QWidget *parent)
    : QWidget(parent), _maxAbsValue(1000.0), _maxIterations(200), _region(-2.0, -2.0, 2.0, 2.0)
{
    _image.fill(qRgb(127, 127, 127));

    _lastReportedCr = 0.0;
    _lastReportedCi = 0.0;

    _panning = false;

    setMouseTracking(true);
}


void MandelbrotView::zoomReset()
{
    setRegion(Region(-2.0, -2.0, 2.0, 2.0));
}

void MandelbrotView::zoom(float scale)
{
    setRegion(region().zoomed(scale));
}

void MandelbrotView::resizeEvent(QResizeEvent *event)
{
    setImage(render(event->size()));
}

void MandelbrotView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.drawImage(0, 0, image());
}

QImage MandelbrotView::render(QSize size)
{
    MandelbrotRenderer renderer;

    return renderer.render(size, _region, _maxAbsValue, _maxIterations);
}

void MandelbrotView::setImage(const QImage& image)
{
    if (_image != image) {
        _image = image;
        update();
    }
}

QImage MandelbrotView::image() const
{
    return _image;
}

void MandelbrotView::setRegion(const Region &region)
{
    if (_region != region) {
        _region = region;
        emit regionChanged(region);

        _image = render(size());
        update();
    }
}

Region MandelbrotView::region() const
{
    return _region;
}

void MandelbrotView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        _panStart = event->pos();
        _panning = true;
    }
}

void MandelbrotView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        _panning = false;

        const float w = width();
        const float h = height();
        const float dx = -(event->pos().x() - _panStart.x());
        const float dy = -(event->pos().y() - _panStart.y());

        setRegion(_region.translated(_region.xRange() * dx / w, _region.yRange() * dy / h));
    }
}

void MandelbrotView::mouseMoveEvent(QMouseEvent *event)
{
    //if (_panning) {
    //    float dx = event->pos().x();
    //    float dy = event->pos().y();
    //}

    const float w = this->width();
    const float h = this->height();
    const float x = event->pos().x();
    const float y = event->pos().y();

    const float c_r = _region.xMin() + _region.xRange() * x / w;
    const float c_i = _region.yMin() + _region.yRange() * y / h;

    if (_lastReportedCr != c_r || _lastReportedCi != c_i) {
        _lastReportedCr = c_r;
        _lastReportedCi = c_i;
        emit pointedAt(c_r, c_i);
    }
}


void MandelbrotView::wheelEvent(QWheelEvent *event)
{
    //QPoint numPixels = event->pixelDelta();
    QPoint numDegrees = event->angleDelta() / 8;

    //if (!numPixels.isNull()) {
    //    scrollWithPixels(numPixels);
    //} else if (!numDegrees.isNull()) {
    if (!numDegrees.isNull()) {
        QPoint numSteps = numDegrees / 15;
        zoomWithSteps(numSteps.y());
    }

    event->accept();
}

void MandelbrotView::zoomWithPixels(float pixels)
{
    Q_UNUSED(pixels)

    // Not implemented
}

void MandelbrotView::zoomWithSteps(int steps)
{
    qDebug() << "zoom steps: "<< steps;

    if (steps > 0) {
        // Zoom in
        zoom( qPow(0.75, steps) );   // TODO Seems wrong the zoom factors should be the other way around
    } else if (steps < 0) {
        // Zoom out
        zoom( qPow(1.25, -steps) );  // TODO Seems wrong the zoom factors should be the other way around
    }
}

