#pragma once

#include <unordered_map>

#define PET_SATIETY "PET_SATIETY"
#define PET_CLEANLINESS "PET_CLEANLINESS"
#define PET_SADNESS "PET_SADNESS"
#define PET_SLEEPINESS "PET_SLEEPINESS"

struct PetNeeds {
    std::unordered_map<const char*, float> needRates;

    PetNeeds()
    {
        needRates[PET_SATIETY] = 0.01;
        needRates[PET_CLEANLINESS] = 0.008;
        needRates[PET_SADNESS] = 0.02;
        needRates[PET_SLEEPINESS] = 0.005;
    }
    void UpdateBlackBoard(class Blackboard& blackboard);
};