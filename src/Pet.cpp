#include "Pet.h"
#include <limits>

Pet::Pet() : petID(0), name(""), species(""), breed(""), age(0),
             size(""), lifestyle(""), available(true) {}

Pet::Pet(int id, const std::string& n, const std::string& sp,
         const std::string& b, int a, const std::string& sz,
         const std::string& life, bool status)
    : petID(id), name(n), species(sp), breed(b), age(a), size(sz),
      lifestyle(life), available(status) {}

Pet::Pet(const Pet& other)
    : petID(other.petID), name(other.name), species(other.species),
      breed(other.breed), age(other.age), size(other.size),
      lifestyle(other.lifestyle), available(other.available) {}

Pet& Pet::operator=(const Pet& other) {
    if (this != &other) {
        petID = other.petID; name = other.name; species = other.species;
        breed = other.breed; age = other.age; size = other.size;
        lifestyle = other.lifestyle; available = other.available;
    }
    return *this;
}

Pet::~Pet() = default;

int Pet::getPetID() const { return petID; }
std::string Pet::getName() const { return name; }
std::string Pet::getSpecies() const { return species; }
std::string Pet::getBreed() const { return breed; }
int Pet::getAge() const { return age; }
std::string Pet::getSize() const { return size; }
std::string Pet::getLifestyle() const { return lifestyle; }
bool Pet::isAvailable() const { return available; }

void Pet::setName(const std::string& n) { name = n; }
void Pet::setBreed(const std::string& b) { breed = b; }
void Pet::setAge(int a) { age = a; }
void Pet::setSize(const std::string& sz) { size = sz; }
void Pet::setLifestyle(const std::string& life) { lifestyle = life; }
void Pet::setAvailability(bool status) { available = status; }

std::string Pet::getType() const { return "Pet"; }

void Pet::display() const {
    std::cout << "\nPet ID: " << petID
              << "\nType: " << getType()
              << "\nName: " << name
              << "\nSpecies: " << species
              << "\nBreed: " << breed
              << "\nAge: " << age
              << "\nSize: " << size
              << "\nLifestyle: " << lifestyle
              << "\nAvailable: " << (available ? "Yes" : "No") << '\n';
}

Pet::operator int() const { return age; }

std::ostream& operator<<(std::ostream& out, const Pet& p) {
    out << "Pet[ID=" << p.petID << ", Name=" << p.name
        << ", Type=" << p.getType() << ", Age=" << p.age << ']';
    return out;
}

std::istream& operator>>(std::istream& in, Pet& p) {
    std::cout << "Pet ID: "; in >> p.petID;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Name: "; std::getline(in, p.name);
    std::cout << "Species: "; std::getline(in, p.species);
    std::cout << "Breed: "; std::getline(in, p.breed);
    std::cout << "Age: "; in >> p.age;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Size: "; std::getline(in, p.size);
    std::cout << "Lifestyle: "; std::getline(in, p.lifestyle);
    std::cout << "Available (1=yes, 0=no): "; in >> p.available;
    return in;
}

bool Pet::operator==(const Pet& other) const { return petID == other.petID; }
bool Pet::operator<(const Pet& other) const { return age < other.age; }
bool Pet::operator!=(const Pet& other) const { return !(*this == other); }
