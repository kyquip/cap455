#ifndef PET_H
#define PET_H

#include <iostream>
#include <string>

class Pet {
protected:
    int petID;
    std::string name;
    std::string species;
    std::string breed;
    int age;
    std::string size;
    std::string lifestyle;
    bool available;

public:
    Pet();
    Pet(int id, const std::string& n, const std::string& sp,
        const std::string& b, int a, const std::string& sz,
        const std::string& life, bool status);
    Pet(const Pet& other);
    Pet& operator=(const Pet& other);
    virtual ~Pet();

    int getPetID() const;
    std::string getName() const;
    std::string getSpecies() const;
    std::string getBreed() const;
    int getAge() const;
    std::string getSize() const;
    std::string getLifestyle() const;
    bool isAvailable() const;

    void setName(const std::string& n);
    void setBreed(const std::string& b);
    void setAge(int a);
    void setSize(const std::string& sz);
    void setLifestyle(const std::string& life);
    void setAvailability(bool status);

    virtual std::string getType() const;
    virtual void display() const;

    // User-defined conversion: a Pet can be converted to its age.
    explicit operator int() const;

    friend std::ostream& operator<<(std::ostream& out, const Pet& p);
    friend std::istream& operator>>(std::istream& in, Pet& p);
    bool operator==(const Pet& other) const;
    bool operator<(const Pet& other) const;
    bool operator!=(const Pet& other) const;
};

#endif
