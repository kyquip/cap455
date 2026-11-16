#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Pet.h"
#include "Adopter.h"
using namespace std;

// Fixed-size Pet binary record //
struct PetRecord {
    int petID;
    char name[50];
    char species[30];
    char breed[50];
    int age;
    char size[20];
    char lifestyle[30];
    bool available;
};

// Fixed-size Adopter binary record //
struct AdopterRecord {
    int adopterID;
    char name[50];
    char contact[20];
    char preferredSpecies[30];
    char preferredSize[20];
    int preferredAge;
    char lifestyle[30];
};

class FileManager {
    public:
        // PET FILE OPERATIONS //
        static void savePet(const Pet& pet);
        static void displayAllPets();
        static bool searchPet(int id, Pet& result);
        static bool updatePet(int id, const Pet& updatedPet);
    
        // ADOPTER FILE OPERATIONS //
        static void saveAdopter(const Adopter& adopter);
        static void displayAllAdopters();
        static bool searchAdopter(int id, Adopter& result);
        static bool updateAdopter(int id, const Adopter& updatedAdopter);
    
    private:
        // Pet conversions //
        static PetRecord toRecord(const Pet& pet);
        static Pet fromRecord(const PetRecord& record);
    
        // Adopter conversions //
        static AdopterRecord toRecord(const Adopter& adopter);
        static Adopter fromRecord(const AdopterRecord& record);
};

#endif