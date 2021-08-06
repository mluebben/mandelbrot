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



    QImage generateImage(QSize size);


signals:


private:
    QImage _image;
};

#endif // MANDELBROTVIEW_H
