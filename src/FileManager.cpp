#include "FileManager.h"
#include "Dog.h"
#include "Cat.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <memory>
#include <typeinfo>

namespace {
template <std::size_t N>
void copyText(char (&dest)[N], const std::string& src) {
    std::strncpy(dest, src.c_str(), N - 1);
    dest[N - 1] = '\0';
}
template <typename Record, typename Predicate>
bool rewriteWithout(const char* path, Predicate shouldRemove) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return false;
    const std::string tempPath = std::string(path) + ".tmp";
    std::ofstream out(tempPath, std::ios::binary | std::ios::trunc);
    if (!out) return false;
    Record record;
    bool removed = false;
    while (in.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        if (shouldRemove(record)) { removed = true; continue; }
        out.write(reinterpret_cast<const char*>(&record), sizeof(Record));
        if (!out) { in.close(); out.close(); std::remove(tempPath.c_str()); return false; }
    }
    bool validRead = in.eof();
    in.close(); out.close();
    if (!validRead || !removed) { std::remove(tempPath.c_str()); return false; }
    if (std::remove(path) != 0 || std::rename(tempPath.c_str(), path) != 0) {
        std::rename(tempPath.c_str(), path);
        return false;
    }
    return true;
}
}

const char* FileManager::petPath() { return "data/pets.dat"; }
const char* FileManager::adopterPath() { return "data/adopters.dat"; }
const char* FileManager::adoptionPath() { return "data/adoptions.dat"; }

PetRecord FileManager::toRecord(const Pet& p) {
    PetRecord r{};
    r.petID = p.getPetID(); r.age = p.getAge(); r.available = p.isAvailable();
    copyText(r.name, p.getName()); copyText(r.species, p.getSpecies());
    copyText(r.breed, p.getBreed()); copyText(r.size, p.getSize());
    copyText(r.lifestyle, p.getLifestyle()); copyText(r.type, p.getType());
    if (const Dog* d = dynamic_cast<const Dog*>(&p)) copyText(r.extra, d->getTrainingLevel());
    else if (const Cat* c = dynamic_cast<const Cat*>(&p)) copyText(r.extra, c->isIndoor() ? "1" : "0");
    return r;
}
AdopterRecord FileManager::toRecord(const Adopter& a) {
    AdopterRecord r{}; r.adopterID = a.getAdopterID(); r.preferredAge = a.getPreferredAge();
    copyText(r.name, a.getName()); copyText(r.contact, a.getContact());
    copyText(r.preferredSpecies, a.getPreferredSpecies()); copyText(r.preferredSize, a.getPreferredSize());
    copyText(r.lifestyle, a.getLifestyle()); return r;
}
AdoptionRecord FileManager::toRecord(const Adoption& a) {
    AdoptionRecord r{}; r.applicationID = a.getApplicationID(); r.petID = a.getPetID();
    r.adopterID = a.getAdopterID(); copyText(r.status, a.getStatus()); return r;
}

bool FileManager::savePet(const Pet& pet) {
    std::ofstream f(petPath(), std::ios::binary | std::ios::app);
    if (!f) { std::cerr << "Cannot open data/pets.dat. Run from the project root.\n"; return false; }
    PetRecord r = toRecord(pet); f.write(reinterpret_cast<const char*>(&r), sizeof(r)); return static_cast<bool>(f);
}
std::vector<Pet> FileManager::getAllPets() {
    std::vector<Pet> pets;
    std::ifstream f(petPath(), std::ios::binary);
    PetRecord r;
    while (f.read(reinterpret_cast<char*>(&r), sizeof(r))) {
        // Matching uses the common Pet attributes; subtype-specific fields are
        // retained in the binary record and are not needed for compatibility.
        pets.emplace_back(r.petID, r.name, r.species, r.breed, r.age,
                          r.size, r.lifestyle, r.available);
    }
    return pets;
}

void FileManager::displayAllPets() {
    std::ifstream f(petPath(), std::ios::binary); PetRecord r; bool found = false;
    while (f.read(reinterpret_cast<char*>(&r), sizeof(r))) {
        found = true;
        if (std::string(r.type) == "Dog") { Dog p(r.petID,r.name,r.species,r.breed,r.age,r.size,r.lifestyle,r.available,r.extra); p.display(); }
        else if (std::string(r.type) == "Cat") { Cat p(r.petID,r.name,r.species,r.breed,r.age,r.size,r.lifestyle,r.available,std::string(r.extra)=="1"); p.display(); }
        else { Pet p(r.petID,r.name,r.species,r.breed,r.age,r.size,r.lifestyle,r.available); p.display(); }
    }
    if (!found) std::cout << "No pet records found.\n";
}
bool FileManager::searchPet(int id, Pet& result) {
    std::ifstream f(petPath(), std::ios::binary); PetRecord r;
    while (f.read(reinterpret_cast<char*>(&r), sizeof(r))) if (r.petID == id) {
        result = Pet(r.petID,r.name,r.species,r.breed,r.age,r.size,r.lifestyle,r.available); return true;
    }
    return false;
}
bool FileManager::updatePet(int id, const Pet& updatedPet) {
    std::fstream f(petPath(), std::ios::binary | std::ios::in | std::ios::out); if (!f) return false;
    PetRecord r;
    while (true) {
        std::streampos pos = f.tellg();
        if (!f.read(reinterpret_cast<char*>(&r), sizeof(r))) break;
        if (r.petID == id) { PetRecord u = toRecord(updatedPet); u.petID = id; f.clear(); f.seekp(pos); f.write(reinterpret_cast<const char*>(&u), sizeof(u)); return static_cast<bool>(f); }
    }
    return false;
}
bool FileManager::deletePet(int id) { return rewriteWithout<PetRecord>(petPath(), [id](const PetRecord& r){ return r.petID == id; }); }

bool FileManager::saveAdopter(const Adopter& a) {
    std::ofstream f(adopterPath(), std::ios::binary | std::ios::app); if (!f) return false;
    AdopterRecord r = toRecord(a); f.write(reinterpret_cast<const char*>(&r), sizeof(r)); return static_cast<bool>(f);
}
void FileManager::displayAllAdopters() {
    std::ifstream f(adopterPath(), std::ios::binary); AdopterRecord r; bool found=false;
    while (f.read(reinterpret_cast<char*>(&r), sizeof(r))) { found=true; Adopter a(r.adopterID,r.name,r.contact,r.preferredSpecies,r.preferredSize,r.preferredAge,r.lifestyle); a.display(); }
    if (!found) std::cout << "No adopter records found.\n";
}
bool FileManager::searchAdopter(int id, Adopter& result) {
    std::ifstream f(adopterPath(), std::ios::binary); AdopterRecord r;
    while (f.read(reinterpret_cast<char*>(&r), sizeof(r))) if (r.adopterID == id) { result=Adopter(r.adopterID,r.name,r.contact,r.preferredSpecies,r.preferredSize,r.preferredAge,r.lifestyle); return true; }
    return false;
}
bool FileManager::updateAdopter(int id, const Adopter& updated) {
    std::fstream f(adopterPath(), std::ios::binary | std::ios::in | std::ios::out); if (!f) return false; AdopterRecord r;
    while (true) { std::streampos pos=f.tellg(); if(!f.read(reinterpret_cast<char*>(&r),sizeof(r))) break;
        if(r.adopterID==id){ AdopterRecord u=toRecord(updated); u.adopterID=id; f.clear(); f.seekp(pos); f.write(reinterpret_cast<const char*>(&u),sizeof(u)); return static_cast<bool>(f); }
    } return false;
}
bool FileManager::deleteAdopter(int id) { return rewriteWithout<AdopterRecord>(adopterPath(), [id](const AdopterRecord& r){ return r.adopterID == id; }); }

bool FileManager::saveAdoption(const Adoption& a) {
    std::ofstream f(adoptionPath(), std::ios::binary | std::ios::app); if (!f) return false;
    AdoptionRecord r=toRecord(a); f.write(reinterpret_cast<const char*>(&r),sizeof(r)); return static_cast<bool>(f);
}
void FileManager::displayAllAdoptions() {
    std::ifstream f(adoptionPath(),std::ios::binary); AdoptionRecord r; bool found=false;
    while(f.read(reinterpret_cast<char*>(&r),sizeof(r))){ found=true; Adoption a(r.applicationID,r.petID,r.adopterID,r.status); a.display(); }
    if(!found) std::cout << "No adoption applications found.\n";
}
bool FileManager::updateAdoptionStatus(int id,const std::string& status) {
    std::fstream f(adoptionPath(),std::ios::binary|std::ios::in|std::ios::out); if(!f) return false; AdoptionRecord r;
    while(true){ std::streampos pos=f.tellg(); if(!f.read(reinterpret_cast<char*>(&r),sizeof(r))) break;
        if(r.applicationID==id){ copyText(r.status,status); f.clear(); f.seekp(pos); f.write(reinterpret_cast<const char*>(&r),sizeof(r)); return static_cast<bool>(f); }
    } return false;
}
bool FileManager::nextApplicationID(int& id) {
    std::ifstream f(adoptionPath(),std::ios::binary); AdoptionRecord r; id=1;
    while(f.read(reinterpret_cast<char*>(&r),sizeof(r))) if(r.applicationID>=id) id=r.applicationID+1;
    return true;
}


bool FileManager::searchAdoption(int id, Adoption& result) {
    std::ifstream f(adoptionPath(), std::ios::binary); AdoptionRecord r;
    while (f.read(reinterpret_cast<char*>(&r), sizeof(r))) {
        if (r.applicationID == id) {
            result = Adoption(r.applicationID, r.petID, r.adopterID, r.status);
            return true;
        }
    }
    return false;
}

bool FileManager::setPetAvailability(int id, bool available) {
    std::fstream f(petPath(), std::ios::binary | std::ios::in | std::ios::out);
    if (!f) return false;
    PetRecord r;
    while (true) {
        std::streampos pos = f.tellg();
        if (!f.read(reinterpret_cast<char*>(&r), sizeof(r))) break;
        if (r.petID == id) {
            r.available = available;
            f.clear(); f.seekp(pos);
            f.write(reinterpret_cast<const char*>(&r), sizeof(r));
            return static_cast<bool>(f);
        }
    }
    return false;
}
