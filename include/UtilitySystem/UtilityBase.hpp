#pragma once


class ActionBase;

class UtilityBase
{
protected:
    ActionBase &_action;

    class Blackboard &_blackboard;

public:
    UtilityBase(Blackboard &blackboard) = delete;

    virtual float Evaluate() const = 0;

    virtual ActionBase &GetAction() const;
};