#ifndef PET_H
#define PET_H

#include <string>
using namespace std;

class Pet {
private:
    int petId;
    string name;
    string species;
    string breed;
    int age;
    string size;
    string gender;
    bool available;

public:
    // Constructor
    Pet();

    // Member functions
    void addPet();
    void displayPet() const;
    void updatePet();

    // Getter
    int getPetId() const;
};

#endif