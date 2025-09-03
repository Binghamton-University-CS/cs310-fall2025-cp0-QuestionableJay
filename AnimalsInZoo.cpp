#include <iostream>
using namespace std;
#include "AnimalsInZoo.h"

AnimalsInZoo::AnimalsInZoo() : numAnimals(0){}

AnimalsInZoo::AnimalsInZoo(Animal one) : numAnimals(1), animal(one){}

void AnimalsInZoo::display() {
  animal.display();
}
