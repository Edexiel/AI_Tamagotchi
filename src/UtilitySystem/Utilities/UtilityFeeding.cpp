//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Utilities/UtilityFeeding.hpp"
#include "PetStats.h"
#include "Curves.h"
#include "UtilitySystem/Blackboard.hpp"

float UtilityFeeding::Evaluate(Blackboard& blackboard) const
{
    return _info.Evaluate(blackboard.GetValue(PET_SATIETY));
}

UtilityFeeding::UtilityFeeding(const std::string_view &name, ActionBase *actionBase) : UtilityBase(name, actionBase) {
    _info = {UtilityCurves::exponential, 0.1, 0, true};
}
