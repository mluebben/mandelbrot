#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mandelbrotview.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _mandelbrotView = new MandelbrotView(ui->frame);
}

MainWindow::~MainWindow()
{
    delete ui;
}
