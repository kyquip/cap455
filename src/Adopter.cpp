#include "Adopter.h"
Adopter::Adopter() : adopterID(0), preferredAge(0) {}
Adopter::Adopter(int id, const std::string& n, const std::string& c,
                 const std::string& species, const std::string& size,
                 int age, const std::string& life)
    : adopterID(id), name(n), contact(c), preferredSpecies(species),
      preferredSize(size), lifestyle(life), preferredAge(age) {}
Adopter::Adopter(const Adopter& other)
    : adopterID(other.adopterID), name(other.name), contact(other.contact),
      preferredSpecies(other.preferredSpecies), preferredSize(other.preferredSize),
      lifestyle(other.lifestyle), preferredAge(other.preferredAge) {}
Adopter& Adopter::operator=(const Adopter& other) {
    if (this != &other) {
        adopterID=other.adopterID; name=other.name; contact=other.contact;
        preferredSpecies=other.preferredSpecies; preferredSize=other.preferredSize;
        preferredAge=other.preferredAge; lifestyle=other.lifestyle;
    }
    return *this;
}
Adopter::~Adopter() = default;
int Adopter::getAdopterID() const { return adopterID; }
std::string Adopter::getName() const { return name; }
std::string Adopter::getContact() const { return contact; }
std::string Adopter::getPreferredSpecies() const { return preferredSpecies; }
std::string Adopter::getPreferredSize() const { return preferredSize; }
int Adopter::getPreferredAge() const { return preferredAge; }
std::string Adopter::getLifestyle() const { return lifestyle; }
void Adopter::setName(const std::string& n) { name = n; }
void Adopter::setContact(const std::string& c) { contact = c; }
void Adopter::setPreferredSpecies(const std::string& s) { preferredSpecies = s; }
void Adopter::setPreferredSize(const std::string& s) { preferredSize = s; }
void Adopter::setPreferredAge(int a) { preferredAge = a; }
void Adopter::setLifestyle(const std::string& l) { lifestyle = l; }
void Adopter::display() const {
    std::cout << "\nAdopter ID: " << adopterID << "\nName: " << name
              << "\nContact: " << contact << "\nPreferred species: " << preferredSpecies
              << "\nPreferred size: " << preferredSize << "\nMaximum preferred age: "
              << preferredAge << "\nLifestyle: " << lifestyle << '\n';
}
