#include "somclass.h"

SOMClass::SOMClass(int width, int height)
{
    this->m_width = width;
    this->m_height = height;

    m_matrix = new Node[this->m_width * this->m_height];
    m_done = false;
    m_iNumIterations = 1000;
    m_winning_node = nullptr;
    m_iIterationCount = 1;
    m_iNumIterations = 0;
    m_dTimeConstant = 0;
    m_dMapRadius = 0;
    m_dNeighbourhoodRadius = 0;
    m_dInfluence = 0;

}
Node * SOMClass::FindBestMatchingNode(int length, double *input_vector)
{
    Node *best;
    double LowestDistance = 999999;
    for(int i = 0; i < this->m_width * this->m_height; i++)
    {
        double dist = m_matrix[i].GetDistance(input_vector);
        if (dist < LowestDistance)
        {
            LowestDistance = dist;

            best = &m_matrix[i];
        }
    }
    return best;
}
//
// int red   = (int)(m_dWeights[0] * 255);
//int green = (int)(m_dWeights[1] * 255);
//int blue  = (int)(m_dWeights[2] * 255);
//

bool SOMClass::Epoch(double **input_vector, int length)
{
 if (m_done) return true;
  srand (time(NULL));

  if(--m_iNumIterations > 0)
  {
    int featureVector = rand() % length;
    m_winning_node = FindBestMatchingNode(length,input_vector[featureVector]);

    //calculate the width of the neighbourhood for this timestep

    m_dNeighbourhoodRadius = m_dMapRadius * exp(-(double)m_iIterationCount/m_dTimeConstant);

    //Now to adjust the weight vector of the BMU and its
    //neighbours

    //For each node calculate the m_dInfluence
    for(int i = 0; i < this->m_width * this->m_height; i++)
    {
        //calculate the Euclidean distance (squared) to this node from the
        //BMU
        double distToNodeSq = (m_winning_node->x - m_matrix[i].x) * (m_winning_node->x - m_matrix[i].x) +
                (m_winning_node->y - m_matrix[i].y) * (m_winning_node->y - m_matrix[i].y);

        double widthSq = m_dNeighbourhoodRadius * m_dNeighbourhoodRadius;

        if(distToNodeSq < widthSq)
        {
           //calculate by how much its weights are adjusted
            m_dInfluence = exp(-(distToNodeSq) / (2*widthSq));

            m_matrix[i].AdjustWeights(input_vector[featureVector],m_dLearningRate,m_dInfluence);

        }
    }

    //reduce the learning rate
    m_dLearningRate = 0.1 * exp(-(double)m_iIterationCount/m_iNumIterations);

    ++m_iIterationCount;
  }
  else
  {
      m_done = true;
  }
}
