#ifndef SOMCLASS_H
#define SOMCLASS_H
#include "node.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class SOMClass
{
private:
    int m_dMapRadius;
    double m_dTimeConstant;
    double m_iIterationCount;
    double m_LearningRate;
    double m_iNumIterations;

    //how much the learning rate is adjusted for nodes within
    //the area of influence
    double m_Influence;

    //the current width of the winning node's area of influence
    double m_dNeighbourhoodRadius;


    int m_width, m_height;

    //the actual latice

    Node m_winning_node;
    Mat clusterImage;

public:
    void ShowResult();
    Node *m_matrix;
    bool m_done;
    Node FindBestMatchingNode(double *input_vector);
    SOMClass(int width, int height);
    bool Epoch( double **input_vector, int length);
};

#endif // SOMCLASS_H
