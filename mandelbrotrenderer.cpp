#include "stdpch.h"
#include "mandelbrotrenderer.h"
#include "complex.h"

MandelbrotRenderer::MandelbrotRenderer()
{

}

QImage MandelbrotRenderer::render(const QSize& size, float xMin, float xMax, float yMin, float yMax, int limit)
{
    qDebug() << "render: " << size << ", " << xMin << ", " << xMax << ", " << yMin << ", " << yMax << ", " << limit;

    QImage image(size, QImage::Format_RGB32);

    int width = size.width();
    int height = size.height();



    for (int i = 0; i < width ;i++)
    {
        for (int j = 0; j < height ; j++)
        {
            Complex c(
                (xMax - xMin) * static_cast<float>(i) / static_cast<float>(width) + xMin,
                (yMax - yMin) * static_cast<float>(j) / static_cast<float>(height) + yMin
            );

            int value = converge(c, limit);
            QRgb color = colorize(value, limit);
            image.setPixel(i, j, color);
        }
    }

    return image;
}

QRgb MandelbrotRenderer::colorize(int value, int limit)
{
    if (value == limit) {
        return qRgb(0, 0, 0);
    }

    int grayScale = 255 * value / limit;
    //qRgb(189, 149, 39);

    return qRgb(grayScale, grayScale, grayScale);
}

int MandelbrotRenderer::converge(const Complex& c, int limit)
{
    Complex z;
    for(int i = 0; i < limit; i++)
    {
        z.square();
        z += c;

        if (z.manhattan() > 1000000) {
            return i;
        }
    }

    return limit;
}
