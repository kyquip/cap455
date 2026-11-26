#ifndef DOG_H
#define DOG_H
#include "Pet.h"
#include <string>

class Dog : public Pet {
private:
    std::string trainingLevel;
public:
    Dog();
    Dog(int id, const std::string& n, const std::string& sp,
        const std::string& b, int a, const std::string& sz,
        const std::string& life, bool status, const std::string& training);
    std::string getTrainingLevel() const;
    std::string getType() const override;
    void display() const override;
};
#endif
