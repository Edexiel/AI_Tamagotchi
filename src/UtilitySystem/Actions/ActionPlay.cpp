//
// Created by bapti on 13/03/2022.
//

#include "UtilitySystem/Actions/ActionPlay.hpp"
#include "UtilitySystem/Blackboard.hpp"
#include "PetStats.h"

void ActionPlay::Execute(Blackboard &blackboard) {
    float lastSleepiness = blackboard.GetValue(PET_SLEEPINESS);
    if (lastSleepiness > 0.1)
    {
        blackboard.SetValue(PET_SADNESS, 1.f);
        blackboard.SetValue(PET_SLEEPINESS, lastSleepiness - 0.1);
    }
}
