#pragma once

#include "UtilitySystem/ActionBase.hpp"

class ActionSleep : public ActionBase
{
public:
    ActionSleep(const std::string_view &name): ActionBase(name) {};

    void Execute(Blackboard& blackboard) override;
};