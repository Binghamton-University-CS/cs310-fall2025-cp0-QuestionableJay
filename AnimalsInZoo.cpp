#include <iostream>
#include "AnimalsInZoo.h"

AnimalsInZoo::AnimalsInZoo() {
  animalArray = new Animal[size]; 
}

AnimalsInZoo::AnimalsInZoo(unsigned int initial_capacity) {
  if (initial_capacity == 0) {
    size = 1;
  } else {
    size = initial_capacity;
  }
  animalArray = new Animal[size];
}

AnimalsInZoo::~AnimalsInZoo() {
  delete [] animalArray;
}

bool AnimalsInZoo::store(Animal &another_animal) {
  if (numAnimals >= size) {
    makeSpace(0);
  }
  animalArray[numAnimals] = another_animal;
  std::cout << "Animal " << animalArray[numAnimals].get_name() << " added to spot " << numAnimals << " of the contained array." << std::endl;
  ++numAnimals;
  return true;
}

bool AnimalsInZoo::remove(const std::string &animal_name) {
  for (unsigned int i = 0; i < numAnimals; ++i) {
    if (animalArray[i].get_name() == animal_name) {
        animalArray[i] = animalArray[numAnimals - 1];
        numAnimals = numAnimals - 1;
        return true;
    }
  }
  std::cout << "Animal " << animal_name << " not found." << std::endl;
  return false;
}

Animal AnimalsInZoo::find(const std::string &animal_name) const {
  for (unsigned int i = 0; i < numAnimals; ++i) {
    if (animalArray[i].get_name() == animal_name) {
      return animalArray[i];
    }
  }
  return Animal(); 
}

void AnimalsInZoo::readSizes(unsigned int &count, unsigned int &cap) const {
  count = numAnimals;
  cap = size;
}

void AnimalsInZoo::show() const {
  for (unsigned int i = 0; i < numAnimals; ++i) {
    unsigned int pounds = (unsigned int)(animalArray[i].get_weight());
    std::cout << i << ": " << animalArray[i].get_name() << ", " << pounds << " lbs";
    if (animalArray[i].is_dangerous()) {
      std::cout << " be careful!";
    }
    std::cout << std::endl;
  }
}

unsigned int AnimalsInZoo::makeSpace(unsigned int how_many) {
  unsigned int oldSize = size;
  unsigned int newSize;

  if (how_many == 0) {
    newSize = size * 2;
  } else {
    newSize = size + how_many;
  }

  Animal *newAnimal = new Animal[newSize];
  for (unsigned int i = 0; i < numAnimals; ++i) {
    newAnimal[i] = animalArray[i];
  }

  delete [] animalArray;
  animalArray = newAnimal;
  size = newSize;

  return size - oldSize;
}
