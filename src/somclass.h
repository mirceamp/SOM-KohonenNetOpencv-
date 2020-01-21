#ifndef SOMCLASS_H
#define SOMCLASS_H
#include "node.h"


class SOMClass
{
private:
    int m_dMapRadius;
    double m_dTimeConstant;
    double m_iIterationCount;
    double m_dLearningRate;
    int m_width, m_height;

    //the actual latice
    Node *m_matrix;

public:
    Node *FindBestMatchingNode(int length, const double *input_vector);
    SOMClass(int width, int height);
};

#endif // SOMCLASS_H
