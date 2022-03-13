#pragma once

#include "UtilitySystem/UtilityBase.hpp"

class UtilityCleaning : UtilityBase
{
public:
    UtilityCleaning(const std::string_view &name, ActionBase *actionBase) : UtilityBase(name, actionBase) {};
    float Evaluate(Blackboard& blackboard) const override;
};

