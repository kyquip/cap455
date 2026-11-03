#include "Pet.h"
#include <iostream>
#include <limits>

using namespace std;

// Constructor
Pet::Pet() {
    petId = 0;
    age = 0;
    available = true;
}

// Add a new pet
void Pet::addPet() {
    cout << "\nEnter Pet ID: ";
    cin >> petId;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Pet Name: ";
    getline(cin, name);

    cout << "Enter Species (Dog/Cat): ";
    getline(cin, species);

    cout << "Enter Breed: ";
    getline(cin, breed);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (age < 0) {
        cout << "Age cannot be negative. Enter again: ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter Size (Small/Medium/Large): ";
    getline(cin, size);

    cout << "Enter Gender (Male/Female): ";
    getline(cin, gender);

    available = true;

    cout << "\nPet added successfully!\n";
}

// Display pet details
void Pet::displayPet() const {
    cout << "\n-----------------------------\n";
    cout << "        PET DETAILS\n";
    cout << "-----------------------------\n";

    cout << "Pet ID: " << petId << endl;
    cout << "Name: " << name << endl;
    cout << "Species: " << species << endl;
    cout << "Breed: " << breed << endl;
    cout << "Age: " << age << endl;
    cout << "Size: " << size << endl;
    cout << "Gender: " << gender << endl;

    cout << "Availability: "
         << (available ? "Available" : "Adopted")
         << endl;
}

// Update pet details
void Pet::updatePet() {
    cout << "\nUpdating details for Pet ID: "
         << petId << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter New Name: ";
    getline(cin, name);

    cout << "Enter New Species (Dog/Cat): ";
    getline(cin, species);

    cout << "Enter New Breed: ";
    getline(cin, breed);

    cout << "Enter New Age: ";
    cin >> age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (age < 0) {
        cout << "Age cannot be negative. Enter again: ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter New Size: ";
    getline(cin, size);

    cout << "Enter New Gender: ";
    getline(cin, gender);

    cout << "\nPet details updated successfully!\n";
}

// Return Pet ID
int Pet::getPetId() const {
    return petId;
}