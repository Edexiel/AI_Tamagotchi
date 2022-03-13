#pragma once

#include "UtilitySystem/UtilityBase.hpp"

class UtilityPlaying : UtilityBase
{
public:
    UtilityPlaying(const std::string_view &name, ActionBase *actionBase) : UtilityBase(name, actionBase) {};
    float Evaluate(Blackboard& blackboard) const override;
};

