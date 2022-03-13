#pragma once

#include "UtilitySystem/ActionBase.hpp"

class ActionClean : public ActionBase
{
public:
    ActionClean(const std::string_view &name): ActionBase(name) {
        _emoji = Emoji::drops;
    };

    void Execute(Blackboard& blackboard) override;
};