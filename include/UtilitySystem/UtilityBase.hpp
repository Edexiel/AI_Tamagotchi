#pragma once


#include "Blackboard.hpp"
#include "UtilityInfo.hpp"

class ActionBase;

class UtilityBase
{
protected:
    ActionBase* _action;
    std::string_view _name;
public:
    UtilityInfo _info{};

    UtilityBase(std::string_view name, ActionBase* actionBase, UtilityInfo utilityInfo = {}) : _name(name),
                                                                                               _action(actionBase),
                                                                                               _info(utilityInfo) {};
    UtilityBase(UtilityBase&& utilityBase) = default;

    virtual float Evaluate(Blackboard& blackboard) const = 0;

    ActionBase* GetAction() const { return _action; }
    const std::string_view GetName() const { return _name; }
};