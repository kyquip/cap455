#include "Cat.h"
Cat::Cat() : Pet(), indoor(true) { species = "Cat"; }
Cat::Cat(int id, const std::string& n, const std::string& sp,
         const std::string& b, int a, const std::string& sz,
         const std::string& life, bool status, bool isIndoor)
    : Pet(id, n, sp.empty() ? "Cat" : sp, b, a, sz, life, status),
      indoor(isIndoor) {}
bool Cat::isIndoor() const { return indoor; }
std::string Cat::getType() const { return "Cat"; }
void Cat::display() const {
    Pet::display();
    std::cout << "Indoor cat: " << (indoor ? "Yes" : "No") << '\n';
}
