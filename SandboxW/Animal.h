#pragma once
class Animal {
 private:
  double height;
  double weight;

 public:
  double get_height() { return height; }
  void set_height(double h) { height = h; }
  double get_weight() { return weight; }
  void set_weight(double w) { weight = w; }
};
