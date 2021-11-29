#pragma once
#include <string>

#include "Animal.h"

class Pet : public Animal {
 //private:  // private == only accessible within this class
 protected: // protected == only accessible within this 
	 // class and any derived classes
  std::string name;
  bool current_rabies_vax;

 public:
  Pet() { name = "unknown";  }
  Pet(std::string n) { name = n; }
  std::string get_name() { return name; }
  void set_name(std::string n) { name = n; }
  bool get_current_rabies_vax() { return current_rabies_vax; }
  void set_current_rabies_vax(bool status) { current_rabies_vax = status; }
  std::string makeSound() { return "errrrrererere"; }
};
