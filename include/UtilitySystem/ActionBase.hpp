#pragma once

#include <string_view>
#include "EmojiSpriteSheet.h"

class Blackboard;

class ActionBase
{
private:
    std::string_view _name;
protected:
    Emoji _emoji;

public :
    ActionBase(std::string_view name) : _name(name) {};
    ActionBase(ActionBase &action) = default;
    virtual ~ActionBase() = default;

    virtual void Execute(Blackboard& blackboard) = 0;
    const std::string_view GetName() const { return _name; }
    Emoji GetEmoji() const {return _emoji;};
};

