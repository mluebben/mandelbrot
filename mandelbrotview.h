#ifndef MANDELBROTVIEW_H
#define MANDELBROTVIEW_H

#include <QWidget>

class MandelbrotView : public QWidget
{
    Q_OBJECT
public:
    explicit MandelbrotView(QWidget *parent = nullptr);

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;








    QImage render(QSize size);


signals:


private:
    int _limit;
    float _xMin;
    float _xMax;
    float _yMin;
    float _yMax;

    QImage _image;
};

#endif // MANDELBROTVIEW_H
