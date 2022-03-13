//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Utilities/UtilityPlaying.hpp"
#include "PetStats.h"
#include "Curves.h"

float UtilityPlaying::Evaluate(Blackboard& blackboard) const
{
    return UtilityCurves::sigmoid(blackboard.GetValue(PET_SADNESS) + 0.2, 10);
}
