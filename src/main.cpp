#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Adopter.h"
#include "Adoption.h"
#include "FileManager.h"
#include "MatchingEngine.h"

using namespace std;

void clearLine() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
int readInt(const string& prompt, int minValue = 0) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= minValue) { clearLine(); return value; }
        cout << "Invalid number. Try again.\n"; cin.clear(); clearLine();
    }
}
string readText(const string& prompt) { string s; cout << prompt; getline(cin,s); return s; }
bool readYesNo(const string& prompt) { int v=readInt(prompt+" (1=yes, 0=no): ",0); while(v>1) v=readInt("Enter 1 or 0: ",0); return v==1; }

unique_ptr<Pet> inputPet(int id) {
    cout << "Choose pet type: 1. Dog  2. Cat\n";
    int type=readInt("Choice: ",1); while(type>2) type=readInt("Choose 1 or 2: ",1);
    string name=readText("Pet name: ");
    string species=(type==1 ? "Dog" : "Cat");
    string breed=readText("Breed: ");
    int age=readInt("Age in years: ",0);
    string size=readText("Size (Small/Medium/Large): ");
    string life=readText("Lifestyle (Indoor/Outdoor): ");
    bool available=readYesNo("Is the pet available?");
    if(type==1) {
        string training=readText("Training level (None/Basic/Trained): ");
        return unique_ptr<Pet>(new Dog(id,name,species,breed,age,size,life,available,training));
    }
    bool indoor=readYesNo("Is this an indoor cat?");
    return unique_ptr<Pet>(new Cat(id,name,species,breed,age,size,life,available,indoor));
}
Adopter inputAdopter(int id) {
    string name=readText("Adopter name: ");
    string contact=readText("Contact number: ");
    string species=readText("Preferred species (Dog/Cat/Any): ");
    string size=readText("Preferred size (Small/Medium/Large/Any): ");
    int age=readInt("Maximum preferred pet age: ",0);
    string life=readText("Lifestyle (Indoor/Outdoor/Any): ");
    return Adopter(id,name,contact,species,size,age,life);
}
void addPet() {
    int id=readInt("New Pet ID: ",1); Pet existing;
    if(FileManager::searchPet(id,existing)){ cout<<"That pet ID already exists.\n"; return; }
    unique_ptr<Pet> p=inputPet(id);
    cout<<(FileManager::savePet(*p)?"Pet saved.\n":"Could not save pet.\n");
}
void searchPet() { int id=readInt("Pet ID to search: ",1); Pet p; if(FileManager::searchPet(id,p)) p.display(); else cout<<"Pet not found.\n"; }
void updatePet() {
    int id=readInt("Pet ID to update: ",1); Pet old;
    if(!FileManager::searchPet(id,old)){ cout<<"Pet not found.\n"; return; }
    cout<<"Current record:"; old.display();
    if(!readYesNo("Replace this pet's details?")) return;
    unique_ptr<Pet> updated=inputPet(id);
    cout<<(FileManager::updatePet(id,*updated)?"Pet updated.\n":"Update failed.\n");
}
void deletePet() {
    int id=readInt("Pet ID to delete: ",1); Pet p;
    if(!FileManager::searchPet(id,p)){ cout<<"Pet not found.\n"; return; }
    p.display(); if(!readYesNo("Confirm permanent deletion?")){ cout<<"Deletion cancelled.\n"; return; }
    cout<<(FileManager::deletePet(id)?"Pet deleted.\n":"Delete failed.\n");
}
void addAdopter() {
    int id=readInt("New Adopter ID: ",1); Adopter old;
    if(FileManager::searchAdopter(id,old)){ cout<<"That adopter ID already exists.\n"; return; }
    Adopter a=inputAdopter(id); cout<<(FileManager::saveAdopter(a)?"Adopter saved.\n":"Could not save adopter.\n");
}
void searchAdopter() { int id=readInt("Adopter ID to search: ",1); Adopter a; if(FileManager::searchAdopter(id,a)) a.display(); else cout<<"Adopter not found.\n"; }
void updateAdopter() {
    int id=readInt("Adopter ID to update: ",1); Adopter old;
    if(!FileManager::searchAdopter(id,old)){ cout<<"Adopter not found.\n"; return; }
    old.display(); if(!readYesNo("Replace this adopter's details?")) return;
    Adopter updated=inputAdopter(id); cout<<(FileManager::updateAdopter(id,updated)?"Adopter updated.\n":"Update failed.\n");
}
void deleteAdopter() {
    int id=readInt("Adopter ID to delete: ",1); Adopter a;
    if(!FileManager::searchAdopter(id,a)){ cout<<"Adopter not found.\n"; return; }
    a.display(); if(!readYesNo("Confirm permanent deletion?")){ cout<<"Deletion cancelled.\n"; return; }
    cout<<(FileManager::deleteAdopter(id)?"Adopter deleted.\n":"Delete failed.\n");
}
void applyForAdoption() {
    int petID=readInt("Pet ID: ",1), adopterID=readInt("Adopter ID: ",1); Pet p; Adopter a;
    if(!FileManager::searchPet(petID,p)){ cout<<"Pet not found.\n"; return; }
    if(!p.isAvailable()){ cout<<"This pet is not available.\n"; return; }
    if(!FileManager::searchAdopter(adopterID,a)){ cout<<"Adopter not found.\n"; return; }
    int appID; FileManager::nextApplicationID(appID); Adoption app(appID,petID,adopterID,"Pending");
    cout<<(FileManager::saveAdoption(app)?"Application submitted. ID: "+to_string(appID)+"\n":"Could not save application.\n");
}
void processApplication() {
    int id=readInt("Application ID: ",1);
    Adoption application;
    if(!FileManager::searchAdoption(id, application)) { cout<<"Application not found.\n"; return; }
    cout<<"1. Approve  2. Reject  3. Keep Pending\n"; int choice=readInt("Choice: ",1);
    while(choice>3) choice=readInt("Choose 1, 2 or 3: ",1);
    string status=(choice==1?"Approved":choice==2?"Rejected":"Pending");
    if(choice==1 && !FileManager::setPetAvailability(application.getPetID(), false)) {
        cout<<"Could not update pet availability; application was not approved.\n"; return;
    }
    if(!FileManager::updateAdoptionStatus(id,status)) {
        if(choice==1) FileManager::setPetAvailability(application.getPetID(), true);
        cout<<"Application status update failed.\n"; return;
    }
    cout<<"Application status updated to "<<status<<".\n";
}
void findMatchingPets() {
    int adopterID = readInt("Adopter ID for recommendations: ", 1);
    Adopter adopter;
    if (!FileManager::searchAdopter(adopterID, adopter)) {
        cout << "Adopter not found.\n";
        return;
    }
    MatchingEngine::displayRecommendations(adopter, FileManager::getAllPets());
}

void demonstrateOOP() {
    cout<<"\n--- Runtime polymorphism / dynamic allocation ---\n";
    unique_ptr<Pet> dog(new Dog(9001,"Demo Dog","Dog","Mixed",4,"Medium","Outdoor",true,"Basic"));
    unique_ptr<Pet> cat(new Cat(9002,"Demo Cat","Cat","Mixed",2,"Small","Indoor",true,true));
    dog->display(); cat->display();
    cout<<"\n--- Operator overloading ---\n";
    cout<<*dog<<"\n"<<*cat<<"\n";
    cout<<"Same ID? "<<((*dog==*cat)?"Yes":"No")<<"\n";
    cout<<"Dog younger than cat? "<<((*dog<*cat)?"Yes":"No")<<"\n";
    cout<<"Different IDs? "<<((*dog!=*cat)?"Yes":"No")<<"\n";
    int age=static_cast<int>(*dog);
    cout<<"Dog age after Pet-to-int conversion: "<<age<<"\n";
    cout<<"Leaving this function destroys both derived objects through virtual base destructor.\n";
}

int main() {
    int choice=0;
    do {
        cout<<"\n========== PET ADOPTION MATCHING DESK (CA-3) ==========\n"
            <<"1. Add Dog/Cat\n2. Display all pets\n3. Search pet\n4. Update pet\n5. Delete pet\n"
            <<"6. Register adopter\n7. Display adopters\n8. Search adopter\n9. Update adopter\n10. Delete adopter\n"
            <<"11. Submit adoption application\n12. View adoption applications\n13. Process application\n"
            <<"14. Demonstrate CA-3 OOP concepts\n15. Find matching pets (compatibility score)\n0. Exit\n";
        choice=readInt("Enter choice: ",0);
        switch(choice) {
            case 1:addPet();break; case 2:FileManager::displayAllPets();break;
            case 3:searchPet();break; case 4:updatePet();break; case 5:deletePet();break;
            case 6:addAdopter();break; case 7:FileManager::displayAllAdopters();break;
            case 8:searchAdopter();break; case 9:updateAdopter();break; case 10:deleteAdopter();break;
            case 11:applyForAdoption();break; case 12:FileManager::displayAllAdoptions();break;
            case 13:processApplication();break; case 14:demonstrateOOP();break;
            case 15:findMatchingPets();break;
            case 0:cout<<"Goodbye!\n";break; default:cout<<"Invalid menu choice.\n";
        }
    } while(choice!=0);
    return 0;
}
