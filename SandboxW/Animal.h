#ifndef ANIMAL_H  
#define ANIMAL_H

class Animal {
 private:
  double height;
  double weight;

 public:
  double get_height() noexcept { return height; }
  void set_height(double h) noexcept { height = h; }
  double get_weight() noexcept { return weight; }
  void set_weight(double w) noexcept { weight = w; }
};
#endif