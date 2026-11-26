#ifndef CAT_H
#define CAT_H
#include "Pet.h"

class Cat : public Pet {
private:
    bool indoor;
public:
    Cat();
    Cat(int id, const std::string& n, const std::string& sp,
        const std::string& b, int a, const std::string& sz,
        const std::string& life, bool status, bool isIndoor);
    bool isIndoor() const;
    std::string getType() const override;
    void display() const override;
};
#endif
