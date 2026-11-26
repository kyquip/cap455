#include "MatchingEngine.h"
#include <algorithm>
#include <cctype>
#include <iostream>

namespace {
std::string normalise(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return value;
}
bool matchesOrAny(const std::string& preference, const std::string& actual) {
    const std::string p = normalise(preference);
    return p.empty() || p == "any" || p == "no preference" ||
           p == normalise(actual);
}
}

int MatchingEngine::calculateScore(const Pet& pet, const Adopter& adopter) {
    int score = 0;
    // README weights: species 30, size 20, age 20, lifestyle 20, availability 10.
    if (matchesOrAny(adopter.getPreferredSpecies(), pet.getSpecies())) score += 30;
    if (matchesOrAny(adopter.getPreferredSize(), pet.getSize())) score += 20;
    if (adopter.getPreferredAge() <= 0 || pet.getAge() <= adopter.getPreferredAge()) score += 20;
    if (matchesOrAny(adopter.getLifestyle(), pet.getLifestyle())) score += 20;
    if (pet.isAvailable()) score += 10;
    return score;
}

std::vector<PetMatch> MatchingEngine::recommend(const Adopter& adopter,
                                                const std::vector<Pet>& pets) {
    std::vector<PetMatch> matches;
    for (const Pet& pet : pets) {
        if (pet.isAvailable()) matches.emplace_back(pet, calculateScore(pet, adopter));
    }
    std::stable_sort(matches.begin(), matches.end(),
        [](const PetMatch& a, const PetMatch& b) { return a.score > b.score; });
    return matches;
}

void MatchingEngine::displayRecommendations(const Adopter& adopter,
                                             const std::vector<Pet>& pets) {
    const std::vector<PetMatch> matches = recommend(adopter, pets);
    std::cout << "\n===== PET RECOMMENDATIONS FOR " << adopter.getName() << " =====\n";
    if (matches.empty()) {
        std::cout << "No available pets found.\n";
        return;
    }
    for (const PetMatch& match : matches) {
        match.pet.display();
        std::cout << "Compatibility: " << match.score << "/100\n";
        if (match.score >= 80) std::cout << "Match level: Excellent\n";
        else if (match.score >= 60) std::cout << "Match level: Good\n";
        else if (match.score >= 40) std::cout << "Match level: Moderate\n";
        else std::cout << "Match level: Low\n";
        std::cout << "----------------------------------\n";
    }
}
