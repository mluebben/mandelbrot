#include "stdpch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mandelbrotview.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _mandelbrotView(nullptr)
{
    ui->setupUi(this);
    initMandelbrotView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMandelbrotView()
{
    _mandelbrotView = new MandelbrotView(ui->centralwidget);

    QHBoxLayout* layout = new QHBoxLayout(ui->centralwidget);
    layout->addWidget(_mandelbrotView);
}

void MainWindow::on_actionExport_triggered()
{
    qDebug() << "Export not implemented";
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionZoomIn_triggered()
{
    qDebug() << "Zoom In not implemented";
}

void MainWindow::on_actionZoomOut_triggered()
{
    qDebug() << "Zoom out not imple";
}

void MainWindow::on_actionReset_triggered()
{
    qDebug() << "Reset view not impl.";
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "Mandelbrot Viewer");
}

void MainWindow::on_actionAboutQt_triggered()
{
    QMessageBox::aboutQt(this);
}

