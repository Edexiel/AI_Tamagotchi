#pragma once

#include "UtilitySystem/UtilityBase.hpp"

class UtilityFeeding : UtilityBase
{
public:
    UtilityFeeding(const std::string_view &name, ActionBase *actionBase);
    float Evaluate(Blackboard& blackboard) const override;
};

