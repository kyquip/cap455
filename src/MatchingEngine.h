#ifndef MATCHING_ENGINE_H
#define MATCHING_ENGINE_H

#include "Adopter.h"
#include "Pet.h"
#include <vector>

struct PetMatch {
    Pet pet;
    int score;
    PetMatch(const Pet& p, int s) : pet(p), score(s) {}
};

class MatchingEngine {
public:
    // Score is out of 100 using the project's README weights.
    static int calculateScore(const Pet& pet, const Adopter& adopter);
    static std::vector<PetMatch> recommend(const Adopter& adopter,
                                           const std::vector<Pet>& pets);
    static void displayRecommendations(const Adopter& adopter,
                                       const std::vector<Pet>& pets);
};

#endif
