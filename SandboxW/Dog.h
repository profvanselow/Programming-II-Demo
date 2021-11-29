#pragma once
#include "Pet.h"
#include <string>

class Dog : public Pet {
 public:
  std::string makeSound() { return "woof"; }
  Dog() {  }
  Dog(std::string name_to_set) : Pet{name_to_set} {}
  void dig_hole() {}
};
