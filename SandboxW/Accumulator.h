#ifndef ACCUMULATOR_H // {
#define ACCUMULATOR_H

class Accumulator {
 private:
  int m_value;

 public:
  /**
   * @brief Constructor to set default value to 0.
   */
  Accumulator() { m_value = 0; }
  /**
   * @brief
   * @param value
   */
  void add(int value) { m_value += value; }

  // Make the reset() function a friend of this class
  friend void reset(Accumulator& accumulator);
};

#endif