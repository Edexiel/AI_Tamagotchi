//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Utilities/UtilityFeeding.hpp"
#include "PetStats.h"
#include "Curves.h"
#include "UtilitySystem/Blackboard.hpp"

float UtilityFeeding::Evaluate(Blackboard& blackboard) const
{
    return 1 - UtilityCurves::exponential(blackboard.GetValue(PET_SATIETY), 0.1);
}
