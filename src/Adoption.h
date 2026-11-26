#ifndef ADOPTION_H
#define ADOPTION_H
#include <string>

class Adoption {
private:
    int applicationID;
    int petID;
    int adopterID;
    std::string status;
public:
    Adoption();
    Adoption(int appID, int pID, int aID, const std::string& state = "Pending");
    int getApplicationID() const;
    int getPetID() const;
    int getAdopterID() const;
    std::string getStatus() const;
    void setStatus(const std::string& state);
    void display() const;
};
#endif
