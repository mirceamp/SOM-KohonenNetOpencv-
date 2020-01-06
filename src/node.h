#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <QDebug>

class Node
{
private:
    //weights
    double *m_w;
    int nrWeights;
    //initializes the weights to a nr between 0 and 1
    //@Weights - feature vector input
    void initializeWeights(int nrWeights);
public:
    //empty constructor
    Node();
    //@Weights - feature vector input
    Node(int Weights);
    //return the distance between the input vector and the weight vector
    //@input_vector - the input vector containing the features
    //it has to be the same size as the weight vector
    double GetDistance(double *input_vector);
};

#endif // NODE_H
