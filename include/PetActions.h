#pragma once

#include "UtilitySystem/Actions/ActionEat.hpp"
#include "UtilitySystem/Actions/ActionSleep.hpp"
#include "UtilitySystem/Actions/ActionClean.hpp"
#include "UtilitySystem/Actions/ActionPlay.hpp"
#include "UtilitySystem/Actions/ActionIdle.hpp"

struct PetActions {
    ActionEat eat = ActionEat("Eat");
    ActionSleep sleep = ActionSleep("Sleep");
    ActionClean clean = ActionClean("Clean");
    ActionPlay play = ActionPlay("Play");
    ActionIdle idle = ActionIdle("Idle");
};