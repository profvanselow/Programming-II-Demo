#include "Accumulator.h"

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator) {
  // And can access the private data of Accumulator objects
  accumulator.m_value = 0;
}