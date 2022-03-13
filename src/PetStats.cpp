#include "PetStats.h"
#include "UtilitySystem/Blackboard.hpp"

#include "raylib.h"

void PetNeeds::UpdateBlackBoard(Blackboard &blackboard)
{
    for (auto pair : needRates)
    {
        blackboard.SetValue(pair.first, blackboard.GetValue(pair.first) - pair.second * GetFrameTime());
    }
}