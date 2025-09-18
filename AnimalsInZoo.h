#ifndef ANIMALSINZOO_H
#define ANIMALSINZOO_H
#include "Animal.h"

class AnimalsInZoo {
public:
  AnimalsInZoo();
  AnimalsInZoo(unsigned int initial_capacity);
  ~AnimalsInZoo();

  bool store(Animal &another_animal);
  bool remove(const std::string &animal_name);
  Animal find(const std::string &animal_name) const;
  void readSizes(unsigned int &count, unsigned int &capacity) const;
  void show() const;
  unsigned int makeSpace(unsigned int how_many = 0);

private:
  unsigned int size = 1;   
  unsigned int numAnimals = 0; 
  Animal *animalArray;   
};

#endif
