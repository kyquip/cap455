#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Pet.h"
#include "Adopter.h"
#include "Adoption.h"
#include <string>
#include <vector>

struct PetRecord {
    int petID;
    char name[50], species[30], breed[50], size[20], lifestyle[30];
    int age;
    bool available;
    char type[10];
    char extra[40]; // Dog: training level; Cat: "1" indoor or "0" outdoor
};
struct AdopterRecord {
    int adopterID;
    char name[50], contact[20], preferredSpecies[30], preferredSize[20], lifestyle[30];
    int preferredAge;
};
struct AdoptionRecord {
    int applicationID, petID, adopterID;
    char status[20];
};

class FileManager {
public:
    static bool savePet(const Pet& pet);
    static void displayAllPets();
    static std::vector<Pet> getAllPets();
    static bool searchPet(int id, Pet& result);
    static bool updatePet(int id, const Pet& updatedPet);
    static bool deletePet(int id);

    static bool saveAdopter(const Adopter& adopter);
    static void displayAllAdopters();
    static bool searchAdopter(int id, Adopter& result);
    static bool updateAdopter(int id, const Adopter& updatedAdopter);
    static bool deleteAdopter(int id);

    static bool saveAdoption(const Adoption& adoption);
    static void displayAllAdoptions();
    static bool updateAdoptionStatus(int applicationID, const std::string& status);
    static bool searchAdoption(int applicationID, Adoption& result);
    static bool setPetAvailability(int petID, bool available);
    static bool nextApplicationID(int& id);

private:
    static const char* petPath();
    static const char* adopterPath();
    static const char* adoptionPath();
    static PetRecord toRecord(const Pet& pet);
    static AdopterRecord toRecord(const Adopter& adopter);
    static AdoptionRecord toRecord(const Adoption& adoption);
};
#endif
