#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <QDebug>
#include <math.h>

class Node
{
private:
    //@Weights - feature vector input
    void initializeWeights(int nrWeights);
public:
    //weights
    double *m_w;
    int nrWeights;
    //initializes the weights to a nr between 0 and 1
    //possition in the lattice
    int x,y;
    //empty constructor
    Node();
    //@Weights - feature vector input
    Node(int Weights);
    //return the distance between the input vector and the weight vector
    //@input_vector - the input vector containing the features
    //it has to be the same size as the weight vector
    double GetDistance( double *input_vector);
    //given the learning rate and a target vector this function
    //adjusts the node weights accordingly
    void AdjustWeights( double *input_vector,
                         const double LearningRate,
                         const double Influence);

};

#endif // NODE_H
