#pragma once


#include "Blackboard.hpp"

class ActionBase;

class UtilityBase
{
protected:
    ActionBase* _action;
    std::string_view _name;

public:
    UtilityBase(std::string_view name, ActionBase* actionBase) : _name(name), _action(actionBase) {};
    UtilityBase(UtilityBase&& utilityBase) = default;

    virtual float Evaluate(Blackboard& blackboard) const = 0;

    ActionBase* GetAction() const { return _action; }
    const std::string_view GetName() const { return _name; }
};