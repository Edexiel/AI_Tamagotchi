#pragma once

#include "UtilitySystem/ActionBase.hpp"

class ActionIdle : public ActionBase
{
public:
    ActionIdle(const std::string_view &name): ActionBase(name) {
        _emoji = Emoji::dots3;
    };

    void Execute(Blackboard& blackboard) override {};
};