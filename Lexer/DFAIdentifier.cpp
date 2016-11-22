#include "DFAIdentifier.h"

DFAIdentifier::DFAIdentifier()
{
  unsigned finalStates[] = {2, 3, 5, 6, 8, 9, 11};
  F = new std::vector<unsigned>(finalStates, finalStates + FCardinality);
}


DFAIdentifier::~DFAIdentifier()
{
  if (F)
  {
    delete F;
    F = nullptr;
  }
    
}
