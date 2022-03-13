//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Utilities/UtilityCleaning.hpp"
#include "PetStats.h"
#include "Curves.h"

float UtilityCleaning::Evaluate(Blackboard& blackboard) const
{
    return UtilityCurves::sigmoid(blackboard.GetValue(PET_CLEANLINESS), 10);
}
