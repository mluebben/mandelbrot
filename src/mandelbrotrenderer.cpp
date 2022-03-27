// SPDX-License-Identifier: GPL-3.0-or-later
//
// Copyright 2022 Matthias Lübben <ml81@gmx.de>
//

#include "stdpch.h"
#include "mandelbrotrenderer.h"
#include "complex.h"
#include "region.h"

MandelbrotRenderer::MandelbrotRenderer()
{

}

QImage MandelbrotRenderer::render(const QSize& size, const Region& region, float maxAbsValue, int maxIterations)
{
    const float xMin = region.xMin();
    const float yMin = region.yMin();
    const float xMax = region.xMax();
    const float yMax = region.yMax();

    qDebug() << "render: " << size << ", " << region << ", " << maxAbsValue << ", " << maxIterations;

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

            int iterations = converge(c, maxAbsValue, maxIterations);
            QRgb color = colorize(iterations, maxIterations);
            image.setPixel(i, j, color);
        }
    }

    return image;
}

QRgb MandelbrotRenderer::colorize(int iterations, int maxIterations)
{
    if (iterations >= maxIterations) {
        return qRgb(0, 0, 0);
    }

    int grayScale = static_cast<int>(255.0 * (static_cast<float>(maxIterations) - static_cast<float>(iterations)) / static_cast<float>(maxIterations));
    int r = grayScale;
    int g = grayScale;
    int b = grayScale;

    return qRgb(r, g, b);
}

int MandelbrotRenderer::converge(const Complex& c, float maxAbsValue, int maxIterations)
{
    Complex z;
    for(int i = 0; i < maxIterations; i++)
    {
        z.square();
        z += c;

        //if (z.manhattan() > 1000000) {
        //    return i;
        //}

        if (z.length() >= maxAbsValue) {
            return i;
        }
    }

    return maxIterations;
}
