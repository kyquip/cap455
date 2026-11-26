#include "Adoption.h"
#include <iostream>
Adoption::Adoption() : applicationID(0), petID(0), adopterID(0), status("Pending") {}
Adoption::Adoption(int appID, int pID, int aID, const std::string& state)
    : applicationID(appID), petID(pID), adopterID(aID), status(state) {}
int Adoption::getApplicationID() const { return applicationID; }
int Adoption::getPetID() const { return petID; }
int Adoption::getAdopterID() const { return adopterID; }
std::string Adoption::getStatus() const { return status; }
void Adoption::setStatus(const std::string& state) { status = state; }
void Adoption::display() const {
    std::cout << "Application ID: " << applicationID << " | Pet ID: " << petID
              << " | Adopter ID: " << adopterID << " | Status: " << status << '\n';
}
