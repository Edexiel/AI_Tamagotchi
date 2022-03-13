//
// Created by Guillaume on 13/03/2022.
//

#include "UtilitySystem/Utilities/UtilityPlaying.hpp"
#include "PetStats.h"
#include "Curves.h"

float UtilityPlaying::Evaluate(Blackboard& blackboard) const
{
    return _info.Evaluate(blackboard.GetValue(PET_SADNESS));
}

UtilityPlaying::UtilityPlaying(const std::string_view &name, ActionBase *actionBase) : UtilityBase(name, actionBase) {
    _info = {UtilityCurves::sigmoid, 10.f, 0.2f, false};
}
