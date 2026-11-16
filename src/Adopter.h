#ifndef ADOPTER_H
#define ADOPTER_H

#include <iostream>
#include <string>

using namespace std;

class Adopter {
private:
    int adopterID;
    string name;
    string contact;
    string preferredSpecies;
    string preferredSize;
    int preferredAge;
    string lifestyle;

public:

    // Default Constructor //
    Adopter();

    // Parameterized Constructor //
    Adopter(int id, string n, string c, string species, string size, int age, string life);

    // Copy Constructor //
    Adopter(const Adopter& other);

    // Destructor //
    ~Adopter();

    // Getters //
    int getAdopterID() const;
    string getName() const;
    string getContact() const;
    string getPreferredSpecies() const;
    string getPreferredSize() const;
    int getPreferredAge() const;
    string getLifestyle() const;

    // Setters //
    void setName(string n);
    void setContact(string c);
    void setPreferredSpecies(string species);
    void setPreferredSize(string size);
    void setPreferredAge(int age);
    void setLifestyle(string life);

    // Display //
    void display() const;
};

#endif