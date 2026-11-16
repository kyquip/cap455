#ifndef PET_H
#define PET_H

#include <string>
using namespace std;

class Pet {
private:
    int petID;
    string name;
    string species;
    string breed;
    int age;
    string size;
    string lifestyle;
    bool available;

public:
    // Default constructor //
    Pet();

    // Parameterized constructor //
    Pet(int id, string n, string sp, string b, int a, string sz, string life, bool status);

    // Copy constructor //
    Pet(const Pet& other);

    // Destructor //
    ~Pet();

    // Getters //
    int getPetID() const;
    string getName() const;
    string getSpecies() const;
    string getBreed() const;
    int getAge() const;
    string getSize() const;
    string getLifestyle() const;
    bool isAvailable() const;

    // Setters //
    void setName(string n);
    void setBreed(string b);
    void setAge(int a);
    void setSize(string sz);
    void setLifestyle(string life);
    void setAvailability(bool status);

    void display() const;
};

#endif