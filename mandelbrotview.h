#ifndef MANDELBROTVIEW_H
#define MANDELBROTVIEW_H

#include <QWidget>
#include "region.h"

class MandelbrotView : public QWidget
{
    Q_OBJECT
public:
    explicit MandelbrotView(QWidget *parent = nullptr);

    void zoomReset();
    void zoom(float scale);

    void setRegion(const Region& region);
    Region region() const;

    QImage image() const;

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent *event) override;

    void zoomWithPixels(float pixels);
    void zoomWithSteps(int steps);

    QImage render(QSize size);


    void setImage(const QImage& image);

signals:
    void regionChanged(const Region& region);
    void pointedAt(float c_r, float c_i);

private:
    float _maxAbsValue;
    int _maxIterations;
    Region _region;

    QImage _image;

    float _lastReportedCr;
    float _lastReportedCi;

    QPoint _panStart;
    bool _panning;
};

#endif // MANDELBROTVIEW_H
