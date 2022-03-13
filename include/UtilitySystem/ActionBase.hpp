#pragma once

#include <string_view>

class Blackboard;

class ActionBase
{
private:
    std::string_view _name;
public :
    ActionBase(std::string_view name) : _name(name) {};
    ActionBase(ActionBase &action) = default;
    virtual ~ActionBase() = default;

    virtual void Execute(Blackboard& blackboard) = 0;
    const std::string_view GetName() const { return _name; }
};

