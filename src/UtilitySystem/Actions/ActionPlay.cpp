//
// Created by bapti on 13/03/2022.
//

#include "UtilitySystem/Actions/ActionPlay.hpp"
#include "UtilitySystem/Blackboard.hpp"
#include "PetStats.h"

void ActionPlay::Execute(Blackboard &blackboard) {
    blackboard.SetValue(PET_SADNESS, 1.f);
}
