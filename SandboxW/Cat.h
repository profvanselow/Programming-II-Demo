#ifndef CAT_H  // {
#define CAT_H

#include <string>

#include "Pet.h"

constexpr int NUM_LIVES = 9;

/**
 * @brief 
*/
class Cat : public Pet {
 private:
  int lives;
  std::string brand_cat_food;

 public:
  // option 1: keep private and use set
  // Cat(std::string n) { set_name(n); }
  // option 2: change field to protected
  Cat() noexcept { lives = NUM_LIVES; }
  Cat(std::string name_to_set) : Pet{name_to_set} { lives = NUM_LIVES; }
  std::string makeSound();

  int const get_lives() noexcept { return lives; }

};

#endif