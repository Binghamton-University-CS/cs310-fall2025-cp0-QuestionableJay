#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
public:
  Animal(){}
  Animal(std::string name, float weight, bool dangerous) {
    this->name = name;
    this->weight = weight;
    this->dangerous = dangerous;
  }

  std::string get_name();
  float get_weight();
  bool is_dangerous();

private:
  std::string name;
  float weight;
  bool dangerous;
};

#endif
