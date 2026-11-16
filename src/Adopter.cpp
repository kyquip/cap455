#include "Adopter.h"

// Default Constructor //
Adopter::Adopter() {
    cout << "\n--- Enter Adopter Details ---\n";
    cout << "Enter Adopter ID: ";
    cin >> adopterID;
    cin.ignore();
    cout << "Enter Adopter Name: ";
    getline(cin, name);
    cout << "Enter Contact Number: ";
    getline(cin, contact);
    cout << "Enter Preferred Species: ";
    getline(cin, preferredSpecies);
    cout << "Enter Preferred Size (Small/Medium/Large): ";
    getline(cin, preferredSize);
    cout << "Enter Preferred Maximum Age: ";
    cin >> preferredAge;
    cin.ignore();
    cout << "Enter Lifestyle (Indoor/Outdoor): ";
    getline(cin, lifestyle);
}

// Parameterized Constructor //
Adopter::Adopter(int id, string n, string c, string species, string size, int age, string life) {

    adopterID = id;
    name = n;
    contact = c;
    preferredSpecies = species;
    preferredSize = size;
    preferredAge = age;
    lifestyle = life;
}

// Copy Constructor //
Adopter::Adopter(const Adopter& other) {
    adopterID = other.adopterID;
    name = other.name;
    contact = other.contact;
    preferredSpecies = other.preferredSpecies;
    preferredSize = other.preferredSize;
    preferredAge = other.preferredAge;
    lifestyle = other.lifestyle;
}

// Destructor //
Adopter::~Adopter() {
    // No dynamically allocated memory to release.
}

// Getters //
int Adopter::getAdopterID() const {
    return adopterID;
}

string Adopter::getName() const {
    return name;
}

string Adopter::getContact() const {
    return contact;
}

string Adopter::getPreferredSpecies() const {
    return preferredSpecies;
}

string Adopter::getPreferredSize() const {
    return preferredSize;
}

int Adopter::getPreferredAge() const {
    return preferredAge;
}

string Adopter::getLifestyle() const {
    return lifestyle;
}

// Setters //
void Adopter::setName(string n) {
    name = n;
}

void Adopter::setContact(string c) {
    contact = c;
}

void Adopter::setPreferredSpecies(string species) {
    preferredSpecies = species;
}

void Adopter::setPreferredSize(string size) {
    preferredSize = size;
}

void Adopter::setPreferredAge(int age) {
    preferredAge = age;
}

void Adopter::setLifestyle(string life) {
    lifestyle = life;
}

// Display Function //
void Adopter::display() const {
    cout << "\n------ Adopter Details ------\n";

    cout << "Adopter ID: " << adopterID << endl;
    cout << "Name: " << name << endl;
    cout << "Contact: " << contact << endl;
    cout << "Preferred Species: " << preferredSpecies << endl;
    cout << "Preferred Size: " << preferredSize << endl;
    cout << "Preferred Age: " << preferredAge << endl;
    cout << "Lifestyle: " << lifestyle << endl;
}