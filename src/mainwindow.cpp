#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mat image;
    image = imread( "/home/mircea/pic/kkk.jpg", 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return;
    }
    Node *n;
    n = new Node();
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
