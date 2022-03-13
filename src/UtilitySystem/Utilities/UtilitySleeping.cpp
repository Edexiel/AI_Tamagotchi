//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Utilities/UtilitySleeping.hpp"
#include "PetStats.h"
#include "Curves.h"

float UtilitySleeping::Evaluate(Blackboard& blackboard) const
{
    return UtilityCurves::sigmoid(blackboard.GetValue(PET_SLEEPINESS), 20);
}

UtilitySleeping::UtilitySleeping(const std::string_view &name, ActionBase *actionBase) : UtilityBase(name, actionBase) {
    _info = {UtilityCurves::sigmoid, 20, 0, false};
}
