#pragma once

#include "UtilitySystem/ActionBase.hpp"

class ActionEat : public ActionBase
{
public:
    ActionEat(const std::string_view &name): ActionBase(name) {};

    void Execute(Blackboard& blackboard) override;
};

