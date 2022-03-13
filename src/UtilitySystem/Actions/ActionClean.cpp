//
// Created by bapti on 13/03/2022.
//

#include "UtilitySystem/Actions/ActionClean.hpp"
#include "UtilitySystem/Blackboard.hpp"
#include "PetStats.h"

void ActionClean::Execute(Blackboard &blackboard) {
    blackboard.SetValue(PET_CLEANLINESS, 1.f);
}