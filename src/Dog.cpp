#include "Dog.h"
Dog::Dog() : Pet(), trainingLevel("Not specified") { species = "Dog"; }
Dog::Dog(int id, const std::string& n, const std::string& sp,
         const std::string& b, int a, const std::string& sz,
         const std::string& life, bool status, const std::string& training)
    : Pet(id, n, sp.empty() ? "Dog" : sp, b, a, sz, life, status),
      trainingLevel(training) {}
std::string Dog::getTrainingLevel() const { return trainingLevel; }
std::string Dog::getType() const { return "Dog"; }
void Dog::display() const {
    Pet::display();
    std::cout << "Training level: " << trainingLevel << '\n';
}
