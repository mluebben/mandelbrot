#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MandelbrotView;

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

private:
    void initMandelbrotView();

private:
    Ui::MainWindow *ui;

    MandelbrotView *_mandelbrotView;

};
#endif // MAINWINDOW_H
