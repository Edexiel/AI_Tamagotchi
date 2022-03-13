//
// Created by bapti on 13/03/2022.
//

#include "UtilitySystem/Actions/ActionSleep.hpp"
#include "UtilitySystem/Blackboard.hpp"
#include "PetStats.h"

void ActionSleep::Execute(Blackboard &blackboard) {
    blackboard.SetValue(PET_SLEEPINESS, 1.f);
}
