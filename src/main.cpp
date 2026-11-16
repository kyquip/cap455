#include <iostream>
#include <string>
#include <limits>
#include "Pet.h"
#include "Adopter.h"
#include "FileManager.h"

using namespace std;

// Helper function to clear input buffer //
void clearInput() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ================= PET FUNCTIONS ================= //
Pet inputPet(int id) {
    string name, species, breed, size, lifestyle;
    int age, availableChoice;

    cout << "\n--- Enter Pet Details ---\n";

    cout << "Enter Pet Name: ";
    getline(cin, name);

    cout << "Enter Species: ";
    getline(cin, species);

    cout << "Enter Breed: ";
    getline(cin, breed);

    cout << "Enter Age: ";
    cin >> age;
    clearInput();

    cout << "Enter Size (Small/Medium/Large): ";
    getline(cin, size);

    cout << "Enter Lifestyle (Indoor/Outdoor): ";
    getline(cin, lifestyle);

    cout << "Is the pet available? (1 = Yes, 0 = No): ";
    cin >> availableChoice;
    clearInput();

    bool available = (availableChoice == 1);

    return Pet(id, name, species, breed, age, size, lifestyle, available);
}

void addPet() {
    int id;

    cout << "\nEnter Pet ID: ";
    cin >> id;
    clearInput();

    // Check whether ID already exists //
    Pet existing(0, "", "", "", 0, "", "", true);

    if (FileManager::searchPet(id, existing)) {
        cout << "\nPet ID already exists!\n";
        return;
    }

    Pet pet = inputPet(id);
    FileManager::savePet(pet);

    cout << "\nPet added successfully!\n";
}

void displayPets() {
    cout << "\n========== ALL PETS ==========\n";
    FileManager::displayAllPets();
}

void searchPetByID() {
    int id;

    cout << "\nEnter Pet ID to search: ";
    cin >> id;

    Pet pet(0, "", "", "", 0, "", "", true);

    if (FileManager::searchPet(id, pet)) {
        cout << "\nPet Found!\n";
        pet.display();
    } else {
        cout << "\nPet not found!\n";
    }
}

void updatePetDetails() {
    int id;

    cout << "\nEnter Pet ID to update: ";
    cin >> id;
    clearInput();

    Pet existing(0, "", "", "", 0, "", "", true);

    if (!FileManager::searchPet(id, existing)) {
        cout << "\nPet not found!\n";
        return;
    }

    cout << "\nCurrent Pet Details:\n";
    existing.display();

    cout << "\nEnter Updated Details:\n";

    Pet updatedPet = inputPet(id);

    if (FileManager::updatePet(id, updatedPet)) {
        cout << "\nPet updated successfully!\n";
    } else {
        cout << "\nUnable to update pet!\n";
    }
}

// ================= ADOPTER FUNCTIONS ================= //
Adopter inputAdopter(int id) {
    string name, contact, species, size, lifestyle;
    int age;

    cout << "\n--- Enter Adopter Details ---\n";

    cout << "Enter Adopter Name: ";
    getline(cin, name);

    cout << "Enter Contact Number: ";
    getline(cin, contact);

    cout << "Enter Preferred Species: ";
    getline(cin, species);

    cout << "Enter Preferred Size (Small/Medium/Large): ";
    getline(cin, size);

    cout << "Enter Preferred Maximum Age: ";
    cin >> age;
    clearInput();

    cout << "Enter Lifestyle (Indoor/Outdoor): ";
    getline(cin, lifestyle);

    return Adopter(id, name, contact, species, size, age, lifestyle);
}

void addAdopter() {
    int id;

    cout << "\nEnter Adopter ID: ";
    cin >> id;
    clearInput();

    Adopter existing(0, "", "", "", "", 0, "");

    if (FileManager::searchAdopter(id, existing)) {
        cout << "\nAdopter ID already exists!\n";
        return;
    }

    Adopter adopter = inputAdopter(id);
    FileManager::saveAdopter(adopter);

    cout << "\nAdopter added successfully!\n";
}

void displayAdopters() {
    cout << "\n========== ALL ADOPTERS ==========\n";
    FileManager::displayAllAdopters();
}

void searchAdopterByID() {
    int id;

    cout << "\nEnter Adopter ID to search: ";
    cin >> id;

    Adopter adopter(0, "", "", "", "", 0, "");

    if (FileManager::searchAdopter(id, adopter)) {
        cout << "\nAdopter Found!\n";
        adopter.display();
    } else {
        cout << "\nAdopter not found!\n";
    }
}

void updateAdopterDetails() {
    int id;

    cout << "\nEnter Adopter ID to update: ";
    cin >> id;
    clearInput();

    Adopter existing(0, "", "", "", "", 0, "");

    if (!FileManager::searchAdopter(id, existing)) {
        cout << "\nAdopter not found!\n";
        return;
    }

    cout << "\nCurrent Adopter Details:\n";
    existing.display();

    cout << "\nEnter Updated Details:\n";

    Adopter updatedAdopter = inputAdopter(id);

    if (FileManager::updateAdopter(id, updatedAdopter)) {
        cout << "\nAdopter updated successfully!\n";
    } else {
        cout << "\nUnable to update adopter!\n";
    }
}

// ================= MAIN MENU ================= //
int main() {
    int choice;

    do {
        cout << "\n\n";
        cout << "====================================\n";
        cout << "       PET ADOPTION MATCHING DESK\n";
        cout << "====================================\n";

        cout << "\n--- PET MANAGEMENT ---\n";
        cout << "1. Add Pet\n";
        cout << "2. Display All Pets\n";
        cout << "3. Search Pet by ID\n";
        cout << "4. Update Pet Details\n";

        cout << "\n--- ADOPTER MANAGEMENT ---\n";
        cout << "5. Add Adopter\n";
        cout << "6. Display All Adopters\n";
        cout << "7. Search Adopter by ID\n";
        cout << "8. Update Adopter Details\n";

        cout << "\n9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        clearInput();

        switch (choice) {
            case 1:
                addPet();
                break;

            case 2:
                displayPets();
                break;

            case 3:
                searchPetByID();
                break;

            case 4:
                updatePetDetails();
                break;

            case 5:
                addAdopter();
                break;

            case 6:
                displayAdopters();
                break;

            case 7:
                searchAdopterByID();
                break;

            case 8:
                updateAdopterDetails();
                break;

            case 9:
                cout << "\nThank you for using Pet Adoption Matching Desk!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}