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

    Mat clusterImage = Mat::zeros(800, 1280, CV_8UC3);

    sc = new SOMClass(1280, 800);

    double **data;
    data = (double **)malloc(9 * sizeof(int *));
    for(int i = 0; i < 9; i++)
        data[i] = (double *)malloc(3 * sizeof(double));

    data[0][0] = 1; data[0][1] = 0; data[0][2] = 0;
    data[0][0] = 0; data[0][1] = 1; data[0][2] = 0;
    data[0][0] = 0; data[0][1] = 0.5; data[0][2] = 0.25;
    data[0][0] = 0; data[0][1] = 0; data[0][2] = 0;
    data[0][0] = 0; data[0][1] = 0; data[0][2] = 1;
    data[0][0] = 0; data[0][1] = 0; data[0][2] = 0.5;
    data[0][0] = 1; data[0][1] = 1; data[0][2] = 0.2;
    data[0][0] = 1; data[0][1] = 0.4; data[0][2] = 0.25;
    data[0][0] = 1; data[0][1] = 0; data[0][2] = 1;

    if(!sc->m_done)
    {
       sc->Epoch(data,9);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
