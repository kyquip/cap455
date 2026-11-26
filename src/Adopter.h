#ifndef ADOPTER_H
#define ADOPTER_H
#include <iostream>
#include <string>

class Adopter {
private:
    int adopterID;
    std::string name, contact, preferredSpecies, preferredSize, lifestyle;
    int preferredAge;
public:
    Adopter();
    Adopter(int id, const std::string& n, const std::string& c,
            const std::string& species, const std::string& size,
            int age, const std::string& life);
    Adopter(const Adopter& other);
    Adopter& operator=(const Adopter& other);
    ~Adopter();

    int getAdopterID() const;
    std::string getName() const;
    std::string getContact() const;
    std::string getPreferredSpecies() const;
    std::string getPreferredSize() const;
    int getPreferredAge() const;
    std::string getLifestyle() const;

    void setName(const std::string& n);
    void setContact(const std::string& c);
    void setPreferredSpecies(const std::string& species);
    void setPreferredSize(const std::string& size);
    void setPreferredAge(int age);
    void setLifestyle(const std::string& life);
    void display() const;
};
#endif
