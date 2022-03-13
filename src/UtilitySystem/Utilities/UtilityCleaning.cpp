//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Utilities/UtilityCleaning.hpp"
#include "PetStats.h"
#include "Curves.h"

float UtilityCleaning::Evaluate(Blackboard& blackboard) const
{
    return _info.Evaluate(blackboard.GetValue(PET_CLEANLINESS));
}

UtilityCleaning::UtilityCleaning(const std::string_view &name, ActionBase *actionBase) : UtilityBase(name, actionBase) {
    _info = {UtilityCurves::sigmoid, 10, 0, false};
}
