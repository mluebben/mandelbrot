// SPDX-License-Identifier: GPL-3.0-or-later
//
// Copyright 2022 Matthias Lübben <ml81@gmx.de>
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MandelbrotView;
class QLabel;
class Region;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_actionExport_triggered();
    void on_actionExit_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionReset_triggered();
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();

    void on_applyPushButton_clicked();

    void on_mandelbrotView_pointedAt(float c_r, float c_i);
    void on_mandelbrotView_regionChanged(const Region& region);

private:
    void initMandelbrotView();
    void initStatusBar();

private:
    Ui::MainWindow *ui;

    MandelbrotView *_mandelbrotView;

    QLabel *_cLabel;
    QLabel *_cminLabel;
    QLabel *_cmaxLabel;
};
#endif // MAINWINDOW_H
