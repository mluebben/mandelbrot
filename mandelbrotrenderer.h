#ifndef MANDELBROTRENDERER_H
#define MANDELBROTRENDERER_H

#include <QtCore>
#include <QtGui>

class QSize;
class QImage;
class Complex;

class MandelbrotRenderer
{
public:
    MandelbrotRenderer();

    QImage render(const QSize& size, float xMin, float xMax, float yMin, float yMax, int limit);

private:
    QRgb colorize(int value, int limit);
    int converge(const Complex& c, int limit);
};

#endif // MANDELBROTRENDERER_H
