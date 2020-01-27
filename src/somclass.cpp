#include "somclass.h"

SOMClass::SOMClass(int width, int height)
{
    this->m_width = width;
    this->m_height = height;
    clusterImage = Mat::zeros(height, width, CV_8UC3);
    m_matrix = new Node[this->m_width * this->m_height];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            m_matrix[i * width + j].x = i;
            m_matrix[i * width + j].y = j;
        }
    }

    m_done = false;
    m_iNumIterations = 1000;
    m_winning_node = m_matrix[0];
    m_iIterationCount = 1;
    m_LearningRate = 0.1;
    m_dMapRadius = max(width, height) / 2;
    m_dTimeConstant = m_iNumIterations / log(m_dMapRadius);
    m_dNeighbourhoodRadius = 0;
    m_Influence = 0;

}
Node SOMClass::FindBestMatchingNode( double *input_vector)
{
    Node best;
    double LowestDistance = 999999;
    for(int i = 0; i < this->m_width * this->m_height; i++)
    {
        double dist = m_matrix[i].GetDistance(input_vector);
        if (dist < LowestDistance)
        {
            LowestDistance = dist;

            best = m_matrix[i];
        }
    }
    return best;
}


bool SOMClass::Epoch(double **input_vector, int length)
{
    if (m_done == true) return true;
    srand (static_cast<unsigned int>(time(nullptr)));

    if(--m_iNumIterations > 0)
    {
        for(int featureVector = 0; featureVector < length; featureVector++)
        {
            //int featureVector = rand() % length;
            m_winning_node = FindBestMatchingNode(input_vector[featureVector]);

            //calculate the width of the neighbourhood for this timestep

            m_dNeighbourhoodRadius = m_dMapRadius * exp(-static_cast<double>(m_iIterationCount/m_dTimeConstant));

            //Now to adjust the weight vector of the BMU and its
            //neighbours

            //For each node calculate the m_dInfluence
            for(int i = 0; i < this->m_width * this->m_height; i++)
            {
                //calculate the Euclidean distance (squared) to this node from the
                //BMU
                double distToNodeSq = (m_winning_node.x - m_matrix[i].x) * (m_winning_node.x - m_matrix[i].x) +
                        (m_winning_node.y - m_matrix[i].y) * (m_winning_node.y - m_matrix[i].y);
                //  qDebug() << m_winning_node.x << " " << m_winning_node.y << "\n";
                double widthSq = m_dNeighbourhoodRadius * m_dNeighbourhoodRadius;

                if(distToNodeSq < widthSq)
                {
                    //calculate by how much its weights are adjusted
                    m_Influence = exp(-(distToNodeSq) / (2*widthSq));
                    m_matrix[i].AdjustWeights(input_vector[featureVector],m_LearningRate,m_Influence);

                }
            }

            //reduce the learning rate
            m_LearningRate = 0.1 * exp(-static_cast<double>(m_iIterationCount/m_iNumIterations));

            ++m_iIterationCount;
            // clusterImage.setTo(255);
        }
    }
    else
    {
        m_done = true;
    }

    return false;
}
void SOMClass::ShowResult()
{
    for(int i = 0; i < this->m_height; i++)
    {
        for(int j = 0; j < this->m_width; j++)
        {
            clusterImage.at<Vec3b>(i,j)[0] = static_cast<unsigned char>(m_matrix[i * this->m_width + j].m_w[0] * 255 + 0.5);
            clusterImage.at<Vec3b>(i,j)[1] = static_cast<unsigned char>(m_matrix[i * this->m_width + j].m_w[1] * 255 + 0.5);
            clusterImage.at<Vec3b>(i,j)[2] = static_cast<unsigned char>(m_matrix[i * this->m_width + j].m_w[2] * 255 + 0.5);
        }
    }
    imshow("Cluser",clusterImage);
    cvWaitKey(0);
}
