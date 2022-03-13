#pragma once

#include "UtilitySystem/ActionBase.hpp"

class ActionPlay : public ActionBase
{
public:
    ActionPlay(const std::string_view &name): ActionBase(name) {};

    void Execute(Blackboard& blackboard) override;
};