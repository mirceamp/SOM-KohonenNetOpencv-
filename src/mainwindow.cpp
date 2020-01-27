#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sc = new SOMClass(800, 600);

    double **data;
    data = static_cast<double **>(malloc(16 * sizeof(int *)));
    for(int i = 0; i < 16; i++)
        data[i] = static_cast<double *>(malloc(3 * sizeof(double)));

    data[0][0] = 1; data[0][1] = 0; data[0][2] = 0;
    data[1][0] = 0; data[1][1] = 1; data[1][2] = 0;
    data[2][0] = 0; data[2][1] = 0.5; data[2][2] = 0.25;
    data[3][0] = 0; data[3][1] = 0; data[3][2] = 0;
    data[4][0] = 0; data[4][1] = 0; data[4][2] = 1;
    data[5][0] = 0; data[5][1] = 0; data[5][2] = 0.5;
    data[6][0] = 1; data[6][1] = 1; data[6][2] = 0.2;
    data[7][0] = 1; data[7][1] = 0.4; data[7][2] = 0.25;
    data[8][0] = 1; data[8][1] = 0; data[8][2] = 1;
    data[9][0] = 0.25; data[9][1] = 0.25; data[9][2] = 0.25;
    data[10][0] = 0.5; data[10][1] = 1; data[10][2] = 0.1;
    data[11][0] = 0.5; data[11][1] = 1; data[11][2] = 0.25;
    data[12][0] = 0.1; data[12][1] = 0.45; data[12][2] = 0.85;
    data[13][0] = 0.6; data[13][1] = 1; data[13][2] = 0.3;
    data[14][0] = 0.8; data[14][1] = 1; data[14][2] = 0.1;
    data[15][0] = 0.3; data[15][1] = 0.2; data[15][2] = 0.5;

    Mat colors = Mat::zeros(800,300,CV_8UC3);
    colors.setTo(255);

    circle(colors,Point(100,100),20, Scalar(255,0,0),-1);
    circle(colors,Point(200,100),20, Scalar(0,255,0),-1);
    circle(colors,Point(100,200),20, Scalar(0,0.5 * 255,0.25 * 255),-1);
    circle(colors,Point(200,200),20, Scalar(0,0,0),-1);
    circle(colors,Point(100,300),20, Scalar(0,0,255),-1);
    circle(colors,Point(200,300),20, Scalar(0,0,0.5 * 255),-1);
    circle(colors,Point(100,400),20, Scalar(255,0.4 * 255,0.25* 255),-1);
    circle(colors,Point(200,400),20, Scalar(255,0,255),-1);
    circle(colors,Point(100,500),20, Scalar(0.25 * 255,0.25 * 255,0.25 * 255),-1);
    circle(colors,Point(200,500),20, Scalar(255 * 0.5, 255,0.1 * 255),-1);
    circle(colors,Point(100,600),20, Scalar(255 * 0.5,255,255 * 0.25),-1);
    circle(colors,Point(200,600),20, Scalar(255 * 0.1,0.45 * 255,0.85 * 255),-1);
    circle(colors,Point(100,700),20, Scalar(255 * 0.6 ,255 ,255 * 0.3),-1);
    circle(colors,Point(200,700),20, Scalar(255 * 0.8, 255,0.1 * 255),-1);
    circle(colors,Point(100,800),20, Scalar(255 * 0.3 ,255 * 0.2, 255 * 0.5),-1);

    imshow("colors of the moon", colors);

    while(!sc->m_done)
    {
       sc->Epoch(data,16);
    }
    sc->ShowResult();
}

MainWindow::~MainWindow()
{
    delete ui;
}
