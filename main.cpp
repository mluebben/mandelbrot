#include "mainwindow.h"

#include <QApplication>

#include "complex.h"

int converge(const Complex& c, int limit)
{
    Complex z;
    for(int i = 0; i < limit; i++)
    {
        z.square();
        z += c;
        if(z.manhattan()>1000000) return i;
    }
    return limit;
}

void render(int* buffer, int width, int height, float xMin, float xMax, float yMin, float yMax, int limit)
{
    for (int i = 0; i < width ;i++)
    {
        for (int j = 0; j < height ; j++)
        {
            Complex c(((xMax-xMin) * (i/width)) + xMin,((yMax-yMin) * (j/height)) + yMin);
            buffer[j * width + i] = converge(c, limit);

        }
    }


}







int main(int argc, char *argv[])
{
    //Complex z(0, 0);
    //Complex c();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
