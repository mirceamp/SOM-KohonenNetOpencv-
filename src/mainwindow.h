#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv2/opencv.hpp>
#include <node.h>
#include <QMainWindow>

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  //  Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
