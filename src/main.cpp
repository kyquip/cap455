#include <iostream>
#include "Pet.h"

using namespace std;

int main() {
    const int MAX_PETS = 100;

    // Array of Pet objects
    Pet pets[MAX_PETS];

    int petCount = 0;
    int choice;

    do {
        cout << "\n================================\n";
        cout << "   PET ADOPTION MATCHING DESK\n";
        cout << "================================\n";
        cout << "1. Add Pet\n";
        cout << "2. Display All Pets\n";
        cout << "3. Search Pet by ID\n";
        cout << "4. Update Pet Details\n";
        cout << "5. Exit\n";
        cout << "================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                if (petCount >= MAX_PETS) {
                    cout << "\nPet storage is full!\n";
                    break;
                }

                pets[petCount].addPet();

                // Check for duplicate Pet ID
                bool duplicate = false;

                for (int i = 0; i < petCount; i++) {
                    if (pets[i].getPetId() ==
                        pets[petCount].getPetId()) {
                        duplicate = true;
                        break;
                    }
                }

                if (duplicate) {
                    cout << "\nError: Pet ID already exists. "
                         << "Record was not added.\n";
                } else {
                    petCount++;
                }

                break;
            }

            case 2: {
                if (petCount == 0) {
                    cout << "\nNo pet records found.\n";
                } else {
                    cout << "\n--- ALL PET RECORDS ---\n";

                    for (int i = 0; i < petCount; i++) {
                        pets[i].displayPet();
                    }
                }

                break;
            }

            case 3: {
                int searchId;
                bool found = false;

                cout << "\nEnter Pet ID to search: ";
                cin >> searchId;

                for (int i = 0; i < petCount; i++) {
                    if (pets[i].getPetId() == searchId) {
                        pets[i].displayPet();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\nPet not found!\n";
                }

                break;
            }

            case 4: {
                int updateId;
                bool found = false;

                cout << "\nEnter Pet ID to update: ";
                cin >> updateId;

                for (int i = 0; i < petCount; i++) {
                    if (pets[i].getPetId() == updateId) {
                        pets[i].updatePet();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\nPet not found!\n";
                }

                break;
            }

            case 5:
                cout << "\nThank you for using "
                     << "Pet Adoption Matching Desk!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}