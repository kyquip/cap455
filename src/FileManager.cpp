#include "FileManager.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

PetRecord FileManager::toRecord(const Pet& pet) {

    PetRecord r{};

    r.petID = pet.getPetID();

    strncpy(r.name, pet.getName().c_str(), sizeof(r.name) - 1);
    strncpy(r.species, pet.getSpecies().c_str(), sizeof(r.species) - 1);
    strncpy(r.breed, pet.getBreed().c_str(), sizeof(r.breed) - 1);
    strncpy(r.size, pet.getSize().c_str(), sizeof(r.size) - 1);
    strncpy(r.lifestyle, pet.getLifestyle().c_str(), sizeof(r.lifestyle) - 1);

    r.age = pet.getAge();
    r.available = pet.isAvailable();

    return r;
}

Pet FileManager::fromRecord(const PetRecord& r) {

    return Pet(r.petID, r.name, r.species, r.breed, r.age, r.size, r.lifestyle, r.available);
}

// Save Pet //
void FileManager::savePet(const Pet& pet) {

    ofstream file("../data/pets.dat", ios::binary | ios::app);

    if (!file) {
        cout << "Unable to open pets.dat\n";
        return;
    }

    PetRecord r = toRecord(pet);

    file.write(reinterpret_cast<const char*>(&r), sizeof(PetRecord));

    if (file)
        cout << "Pet saved successfully!\n";
    else
        cout << "Error saving pet!\n";

    file.close();
}


// Display All Pets //
void FileManager::displayAllPets() {

    ifstream file("../data/pets.dat", ios::binary);

    if (!file) {
        cout << "No pet records found!\n";
        return;
    }

    PetRecord r;

    while (file.read(reinterpret_cast<char*>(&r), sizeof(PetRecord))) {
        Pet pet = fromRecord(r);
        pet.display();
    }

    file.close();
}


// Search Pet using seekg //
bool FileManager::searchPet(int id, Pet& result) {

    ifstream file("../data/pets.dat", ios::binary);

    if (!file) {
        return false;
    }

    PetRecord r;

    while (true) {
        streampos position = file.tellg();

        if (!file.read(reinterpret_cast<char*>(&r), sizeof(PetRecord))) break;
        if (r.petID == id) {
            file.clear();
            file.seekg(position);

            file.read(reinterpret_cast<char*>(&r), sizeof(PetRecord));

            result = fromRecord(r);

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


// Update Pet using seekp //
bool FileManager::updatePet(int id, const Pet& updatedPet) {

    fstream file("../data/pets.dat", ios::binary | ios::in | ios::out);

    if (!file) return false;

    PetRecord r;

    while (true) {

        streampos position = file.tellg();

        if (!file.read(reinterpret_cast<char*>(&r), sizeof(PetRecord)))  break;
        if (r.petID == id) {
            PetRecord updated = toRecord(updatedPet);
            updated.petID = id;

            file.clear();
            file.seekp(position);

            file.write(reinterpret_cast<const char*>(&updated), sizeof(PetRecord));

            bool success = static_cast<bool>(file);

            file.close();
            return success;
        }
    }

    file.close();
    return false;
}

AdopterRecord FileManager::toRecord(const Adopter& adopter) {

    AdopterRecord r{};

    r.adopterID = adopter.getAdopterID();

    strncpy(r.name, adopter.getName().c_str(), sizeof(r.name) - 1);
    strncpy(r.contact, adopter.getContact().c_str(), sizeof(r.contact) - 1);
    strncpy(r.preferredSpecies, adopter.getPreferredSpecies().c_str(), sizeof(r.preferredSpecies) - 1);
    strncpy(r.preferredSize, adopter.getPreferredSize().c_str(), sizeof(r.preferredSize) - 1);
    r.preferredAge = adopter.getPreferredAge();
    strncpy(r.lifestyle, adopter.getLifestyle().c_str(), sizeof(r.lifestyle) - 1);

    return r;
}


// Convert AdopterRecord into Adopter object //
Adopter FileManager::fromRecord(const AdopterRecord& r) {
    return Adopter(r.adopterID, r.name, r.contact, r.preferredSpecies, r.preferredSize, r.preferredAge, r.lifestyle);
}


// Save Adopter //
void FileManager::saveAdopter(const Adopter& adopter) {

    ofstream file("../data/adopters.dat", ios::binary | ios::app);

    if (!file) {
        cout << "Unable to open adopters.dat\n";
        return;
    }

    AdopterRecord r = toRecord(adopter);

    file.write(reinterpret_cast<const char*>(&r), sizeof(AdopterRecord));

    if (file)
        cout << "Adopter saved successfully!\n";
    else
        cout << "Error saving adopter!\n";

    file.close();
}


// Display All Adopters //
void FileManager::displayAllAdopters() {

    ifstream file("../data/adopters.dat", ios::binary);

    if (!file) {
        cout << "No adopter records found!\n";
        return;
    }

    AdopterRecord r;

    while (file.read(reinterpret_cast<char*>(&r), sizeof(AdopterRecord))) {
        Adopter adopter = fromRecord(r);
        adopter.display();
    }

    file.close();
}


// Search Adopter using seekg //
bool FileManager::searchAdopter(int id, Adopter& result) {
    ifstream file("../data/adopters.dat", ios::binary);

    if (!file) return false;

    AdopterRecord r;

    while (true) {
        streampos position = file.tellg();

        if (!file.read(reinterpret_cast<char*>(&r), sizeof(AdopterRecord)))  break;

        if (r.adopterID == id) {
            file.clear();
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&r), sizeof(AdopterRecord));

            result = fromRecord(r);

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


// Update Adopter using seekp //
bool FileManager::updateAdopter(
    int id, const Adopter& updatedAdopter) {

    fstream file("../data/adopters.dat", ios::binary | ios::in | ios::out);

    if (!file) return false;

    AdopterRecord r;

    while (true) {
        streampos position = file.tellg();

        if (!file.read(reinterpret_cast<char*>(&r), sizeof(AdopterRecord)))  break;

        if (r.adopterID == id) {
            AdopterRecord updated = toRecord(updatedAdopter);

            // Preserve original unique ID //
            updated.adopterID = id;

            file.clear();
            file.seekp(position);

            file.write(reinterpret_cast<const char*>(&updated), sizeof(AdopterRecord));

            bool success = static_cast<bool>(file);

            file.close();
            return success;
        }
    }

    file.close();
    return false;
}