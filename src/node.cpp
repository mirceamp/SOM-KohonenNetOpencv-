#include "node.h"

Node::Node()
{
    m_w = new double[3];
    nrWeights = 3;
    initializeWeights(nrWeights);
}
Node::Node(int Weights):
    nrWeights(Weights)
{
    m_w = new double[Weights];
    initializeWeights(nrWeights);
}
void Node::initializeWeights(int nrWeights)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i = 0; i < nrWeights; i++)
    {
        m_w[i] = (static_cast<double>( rand() % 1000000000) / (RAND_MAX)) ;
        qDebug() << m_w[i] << "\n";
    }
}
double Node::GetDistance(double *input_vector)
{
  double result = 0;
  for(int i = 0; i < nrWeights; i++)
  {
      result += (input_vector[i] - m_w[i]) * (input_vector[i] - m_w[i]);
  }
  return result;
}

void Node::AdjustWeights( double *input_vector,
                     const double LearningRate,
                     const double Influence)
{
   for(int w = 0; w < nrWeights; w++)
   {
       m_w[w] += LearningRate * Influence *  (input_vector[w] - m_w[w]);
   }
}
