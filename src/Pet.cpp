#include "Pet.h"
#include <iostream>
#include "Pet.h"

Pet::Pet() {
    cout << "\n--- Enter Pet Details ---\n";
    cout << "Enter Pet ID: ";
    cin >> petID;
    cin.ignore();
    cout << "Enter Pet Name: ";
    getline(cin, name);
    cout << "Enter Species: ";
    getline(cin, species);
    cout << "Enter Breed: ";
    getline(cin, breed);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Size (Small/Medium/Large): ";
    getline(cin, size);
    cout << "Enter Lifestyle (Indoor/Outdoor): ";
    getline(cin, lifestyle);
    cout << "Is the pet available? (1 = Yes, 0 = No): ";
    cin >> available;
}

Pet::Pet(int id, string n, string sp, string b,
         int a, string sz, string life, bool status) {
    petID = id;
    name = n;
    species = sp;
    breed = b;
    age = a;
    size = sz;
    lifestyle = life;
    available = status;
}

Pet::Pet(const Pet& other) {
    petID = other.petID;
    name = other.name;
    species = other.species;
    breed = other.breed;
    age = other.age;
    size = other.size;
    lifestyle = other.lifestyle;
    available = other.available;
}

Pet::~Pet() {
    // No dynamic memory to release.
}

// Getter implementations
int Pet::getPetID() const { return petID; }
string Pet::getName() const { return name; }
string Pet::getSpecies() const { return species; }
string Pet::getBreed() const { return breed; }
int Pet::getAge() const { return age; }
string Pet::getSize() const { return size; }
string Pet::getLifestyle() const { return lifestyle; }
bool Pet::isAvailable() const { return available; }

// Setter implementations
void Pet::setName(string n) { name = n; }
void Pet::setBreed(string b) { breed = b; }
void Pet::setAge(int a) { age = a; }
void Pet::setSize(string sz) { size = sz; }
void Pet::setLifestyle(string life) { lifestyle = life; }
void Pet::setAvailability(bool status) {
    available = status;
}

void Pet::display() const {
    cout << "\nPet ID: " << petID;
    cout << "\nName: " << name;
    cout << "\nSpecies: " << species;
    cout << "\nBreed: " << breed;
    cout << "\nAge: " << age;
    cout << "\nSize: " << size;
    cout << "\nLifestyle: " << lifestyle;
    cout << "\nAvailable: "
         << (available ? "Yes" : "No") << endl;
}