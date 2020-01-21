#include "somclass.h"

SOMClass::SOMClass(int width, int height)
{
  this->m_width = width;
  this->m_height = height;

   m_matrix = new Node[this->m_width * this->m_height];
}
Node * SOMClass::FindBestMatchingNode(int length, const double *input_vector)
{
  Node *best;
  for(int i = 0; i < this->m_width * this->m_height; i++)
  {
     //TO DO
  }
}
