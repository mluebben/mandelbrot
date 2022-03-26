#ifndef MANDELBROTRENDERER_H
#define MANDELBROTRENDERER_H

#include <QtCore>
#include <QtGui>

class QSize;
class QImage;
class Complex;
class Region;

class MandelbrotRenderer
{
public:
    MandelbrotRenderer();

    QImage render(const QSize& size, const Region& region, float maxAbsValue, int maxIterations);

private:
    QRgb colorize(int value, int limit);
    int converge(const Complex& c, float maxAbsValue, int maxIterations);
};

#endif // MANDELBROTRENDERER_H
