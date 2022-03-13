#pragma once

#include "UtilitySystem/ActionBase.hpp"

class ActionPlay : public ActionBase
{
public:
    ActionPlay(const std::string_view &name): ActionBase(name) {
        _emoji = Emoji::faceSad;
    };

    void Execute(Blackboard& blackboard) override;
};