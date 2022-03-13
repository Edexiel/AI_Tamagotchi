#pragma once

#include "UtilitySystem/UtilityBase.hpp"

class UtilitySleeping : UtilityBase
{
public:
    UtilitySleeping(const std::string_view &name, ActionBase *actionBase);
    float Evaluate(Blackboard& blackboard) const override;
};

