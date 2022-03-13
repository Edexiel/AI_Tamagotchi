//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Actions/ActionEat.hpp"
#include "UtilitySystem/Blackboard.hpp"
#include "PetStats.h"

void ActionEat::Execute(Blackboard& blackboard) {
    blackboard.SetValue(PET_SATIETY, 1);
}
