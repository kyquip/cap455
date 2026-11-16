# 🐾 Pet Adoption Matching Desk

**MCA Minor Project | CAP455 – Object-Oriented Programming Using C++ | Session 2026–27**

---

## 1. Project Overview

The **Pet Adoption Matching Desk** is a menu-driven C++ application designed to simplify the pet adoption process by connecting potential adopters with suitable pets.

The system maintains information about available pets, adopter profiles and adoption records. It also provides a matching mechanism that recommends suitable pets based on an adopter's preferences, including animal type, age, size and lifestyle.

The main objective is to demonstrate practical applications of Object-Oriented Programming concepts in C++ while developing a structured and user-friendly pet adoption management system.

## 2. Problem Statement

Finding a suitable pet for adoption can be challenging because potential adopters need to consider several factors, such as pet size, age, breed, activity requirements and living conditions.

Managing pet information and adoption applications manually can also lead to duplicate records, data loss and inefficient searching.

The Pet Adoption Matching Desk aims to address these problems through a centralized application that manages pet records, adopter information and adoption matching.

## 3. Project Objectives

- Develop a structured pet adoption management system using C++.
- Maintain records of pets and potential adopters.
- Provide searching and filtering facilities.
- Recommend suitable pets based on adopter preferences.
- Calculate compatibility scores for pet-adopter matching.
- Manage adoption applications and adoption records.
- Implement permanent data storage using file handling.
- Demonstrate Object-Oriented Programming concepts.
- Ensure proper validation and error handling.

## 4. Key Features

### 4.1 Pet Management
- Add new pet records.
- View all registered pets.
- Search pets using unique IDs.
- Update pet information.
- Delete pet records.
- Track pet availability.

### 4.2 Adopter Management
- Register new adopters.
- View adopter profiles.
- Search adopters using unique IDs.
- Update adopter information.
- Delete adopter records.
- Store adoption preferences.

### 4.3 Pet Matching System
- Match pets based on preferred species.
- Compare preferred pet size.
- Compare preferred age range.
- Consider adopter lifestyle.
- Calculate compatibility scores.
- Display the most suitable pets first.

### 4.4 Adoption Management
- Submit adoption applications.
- View pending applications.
- Approve or reject applications.
- Maintain adoption records.
- Update pet availability after successful adoption.

### 4.5 Search and Reports
- View available pets.
- View adopted pets.
- Search registered adopters.
- View pending adoption applications.
- Generate basic adoption statistics.

### 4.6 Data Management
- Store records in files.
- Load existing records when the application starts.
- Update stored records.
- Provide data backup functionality.

## 5. Technology Stack

| Technology | Purpose |
|---|---|
| C++ | Primary programming language |
| OOP | Application architecture |
| File Handling | Permanent data storage |
| STL | Searching, sorting and record management |
| Binary Files | Fixed-size record persistence |
| Git & GitHub | Version control |
| Standard C++ Compiler | Compilation and execution |

## 6. Object-Oriented Programming Concepts

The project demonstrates the following C++ concepts:

- Classes and Objects
- Encapsulation
- Inheritance
- Polymorphism
- Constructors and Destructors
- Copy Constructor
- Static Members
- Inline Functions
- Friend Functions
- `this` Pointer
- Operator Overloading
- Virtual Functions
- Virtual Destructors
- Dynamic Memory Allocation
- Function Templates
- Class Templates
- Exception Handling

## 7. Project Modules

The application is organized into the following modules:

| Module | Responsibility |
|---|---|
| Pet Management | Managing pet records |
| Adopter Management | Managing adopter profiles |
| Matching Engine | Finding suitable pets |
| Adoption Management | Managing applications and adoptions |
| Search & Reports | Searching and displaying information |
| File Management | Saving and retrieving records |

## 8. Project Development Phases

Development follows the four assessment phases specified in the CAP455 Minor Project Quick Guide.

### CA1 – Design & Create (Day 7)

- Design the Pet and Adopter classes.
- Implement Create and Read operations.
- Use arrays of objects and pointers.
- Implement static members, inline functions and friend functions.
- Add input validation and duplicate ID prevention.
- Prepare the proposal, UML diagram, flowchart and data dictionary.

### CA2 – Persist & Search (Day 14)

- Implement constructors and destructors.
- Implement binary file handling using `fstream`.
- Save and retrieve pet and adopter records.
- Implement searching using `seekg()`.
- Implement basic updating using `seekp()`.
- Ensure records remain available after restarting the application.

### CA3 – Reuse & Delete (Day 28)

- Implement inheritance using Pet, Dog and Cat classes.
- Implement operator overloading.
- Implement type conversion.
- Demonstrate dynamic memory allocation.
- Implement virtual functions and virtual destructors.
- Add safe Update and Delete operations.
- Test normal, invalid and boundary cases.

### CA4 – Integrate & Defend (Day 42)

- Integrate all application modules.
- Implement complete CRUD operations.
- Add custom exception handling.
- Implement function and class templates.
- Use STL containers such as `vector` and `list`.
- Demonstrate `sort()`, `find_if()` and `count_if()`.
- Implement the compatibility scoring system.
- Add at least one advanced feature, such as data backup.
- Prepare the final report, repository and demonstration.

## 9. Compatibility Scoring System

The matching engine uses a compatibility score to recommend suitable pets to adopters.

The proposed scoring criteria are:

| Matching Criteria | Weight |
|---|---:|
| Preferred Species | 30 |
| Preferred Size | 20 |
| Preferred Age Range | 20 |
| Lifestyle Compatibility | 20 |
| Pet Availability | 10 |
| **Total** | **100** |

The application calculates a score for each eligible pet and displays recommendations in descending order of compatibility.

A higher score indicates a closer match with the adopter's preferences.

## 10. Project Folder Structure

```text
Pet-Adoption-Matching-Desk/
│
├── docs/
│   ├── ProjectProposal.pdf
│   ├── UML_Diagram.pdf
│   ├── Flowchart.pdf
│   └── DataDictionary.pdf
│
├── src/
│   ├── main.cpp
│   ├── Pet.h
│   ├── Pet.cpp
│   ├── Adopter.h
│   ├── Adopter.cpp
│   ├── Dog.h
│   ├── Dog.cpp
│   ├── Cat.h
│   ├── Cat.cpp
│   ├── MatchingEngine.h
│   ├── MatchingEngine.cpp
│   ├── Adoption.h
│   ├── Adoption.cpp
│   ├── FileManager.h
|   └── FileManager.cpp
│
├── data/
│   ├── pets.dat
│   ├── adopters.dat
│   └── adoptions.dat
│
├── tests/
│   └── test_cases.txt
│
├── README.md
└── .gitignore
```

*Note: The folder and file structure represents the planned organization. Files and modules will be added as development progresses.*

## 11. Installation and Execution

### Prerequisites

- A C++ compiler such as GCC or Clang.
- C++11 or later.
- Visual Studio Code, Code::Blocks or another C++ IDE.
- Git (recommended).

### Clone the Repository

```bash
git clone https://github.com/kyquip/cap455.git
```

Navigate to the project directory:

```bash
cd Pet-Adoption-Matching-Desk
```

### Compile the Project

Once the source files are implemented, compile using:

```bash
g++ -std=c++17 *.cpp -o main
```

### Run the Application

On Linux or macOS:

```bash
./pet_adoption
```

On Windows:

```bash
pet_adoption.exe
```

*The compilation command assumes that the implementation files are stored in the `src` directory and that all required source files are included.*

## 12. Application Menu

The proposed main menu is:

```text
========================================
       PET ADOPTION MATCHING DESK
========================================

1. Pet Management
2. Adopter Management
3. Find Matching Pets
4. Adoption Applications
5. Adoption Records
6. Search & Reports
7. Backup Data
8. Exit

========================================
Enter your choice:
```

## 13. Testing

The application will be tested using the following scenarios:

- Adding valid pet records.
- Adding duplicate pet IDs.
- Registering new adopters.
- Searching for existing and non-existing records.
- Updating pet and adopter information.
- Deleting records with confirmation.
- Matching pets with different preferences.
- Handling pets with no suitable matches.
- Processing adoption applications.
- Preventing adoption of unavailable pets.
- Saving and retrieving records after restarting the application.
- Handling invalid menu choices and inputs.

Detailed test cases and expected results will be maintained in the `tests` directory.

## 14. Future Enhancements

Possible future improvements include:

- Graphical user interface.
- Pet photographs and detailed profiles.
- Advanced recommendation algorithms.
- Email notifications for adoption applications.
- Adoption application history.
- More detailed adoption analytics.
- Integration with an online pet adoption platform.

## 15. Academic Information

**Project Title:** Pet Adoption Matching Desk  
**Course:** MCA  
**Subject:** CAP455 – Object-Oriented Programming Using C++  
**Session:** 2026–27  
**Project Type:** Minor Project  
**Development Language:** C++

This project is developed as an academic exercise to demonstrate the practical implementation of C++ programming and Object-Oriented Programming concepts.

## 16. Academic Integrity

This is an individual academic project. All implementation, documentation and demonstrations should be understood and explainable by the student.

Any external resources or AI-assisted learning tools used during development should be disclosed in accordance with faculty guidelines.

---

**Pet Adoption Matching Desk – Making Pet Adoption More Organized and Accessible.** 🐾