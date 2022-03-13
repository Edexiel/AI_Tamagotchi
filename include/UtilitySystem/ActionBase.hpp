#pragma once

class Blackboard;

class ActionBase
{
protected:
    Blackboard *_blackboard;

    ActionBase(Blackboard &);

public :
    ActionBase() = delete;

    ActionBase(ActionBase &action);

    virtual void Execute() = 0;
};

