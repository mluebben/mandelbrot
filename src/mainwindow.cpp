// SPDX-License-Identifier: GPL-3.0-or-later
//
// Copyright 2022 Matthias Lübben <ml81@gmx.de>
//

#include "stdpch.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mandelbrotview.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _mandelbrotView(nullptr)
{
    ui->setupUi(this);
    initMandelbrotView();
    initStatusBar();
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

    connect(_mandelbrotView, &MandelbrotView::regionChanged, this , &MainWindow::on_mandelbrotView_regionChanged);
    connect(_mandelbrotView, &MandelbrotView::pointedAt, this, &MainWindow::on_mandelbrotView_pointedAt);
}

void MainWindow::initStatusBar()
{
    _cLabel = new QLabel("c: 5", ui->statusbar);
    _cminLabel = new QLabel("min: 5", ui->statusbar);
    _cmaxLabel = new QLabel("max: 5", ui->statusbar);

    ui->statusbar->addPermanentWidget(_cLabel);
    ui->statusbar->addPermanentWidget(_cminLabel);
    ui->statusbar->addPermanentWidget(_cmaxLabel);

    on_mandelbrotView_regionChanged(_mandelbrotView->region());
    on_mandelbrotView_pointedAt(0.0, 0.0);
}

void MainWindow::on_actionExport_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export as image", QString(), "Image (*.png)");
    if (fileName.isNull()) {
        return;
    }

    QImage image = _mandelbrotView->image();
    if (!image.save(fileName, "PNG")) {
        QMessageBox::critical(this, "Error", "Unable to save file.");
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionZoomIn_triggered()
{
    _mandelbrotView->zoom(0.75);
}

void MainWindow::on_actionZoomOut_triggered()
{
    _mandelbrotView->zoom(1.25);
}

void MainWindow::on_actionReset_triggered()
{
    _mandelbrotView->zoomReset();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "Mandelbrot Viewer");
}

void MainWindow::on_actionAboutQt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_applyPushButton_clicked()
{
    _mandelbrotView->setRegion(
        Region(
            ui->xMinDoubleSpinBox->value(),
            ui->xMaxDoubleSpinBox->value(),
            ui->yMinDoubleSpinBox->value(),
            ui->yMaxDoubleSpinBox->value()
        )
    );
}

void MainWindow::on_mandelbrotView_pointedAt(float c_r, float c_i)
{
    _cLabel->setText("c: " + QString::number(c_r) + " + " + QString::number(c_i) + "i");
}

void MainWindow::on_mandelbrotView_regionChanged(const Region& region)
{
    _cminLabel->setText("c<sub>min</sub>: " + QString::number(region.xMin()) + " + " + QString::number(region.yMin()) + "i");
    _cmaxLabel->setText("c<sub>max</sub>: " + QString::number(region.xMax()) + " + " + QString::number(region.yMax()) + "i");
}
