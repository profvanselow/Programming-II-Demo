#pragma once
#include <string>

#include "Pet.h"

class Cat : public Pet {
 private:
  int lives;
  std::string brand_cat_food;

 public:
  // option 1: keep private and use set
  // Cat(std::string n) { set_name(n); }
  // option 2: change field to protected
  Cat() { lives = 9; }
  Cat(std::string name_to_set) : Pet{name_to_set} {}
  std::string makeSound();
};
