#pragma once

#include "raylib.h"
#include "UtilitySystem/UtilitySystem.hpp"
#include "PetActions.h"
#include "PetStats.h"

class Pet {
public:
    Pet();

    void Draw(Texture &spriteSheet);

    void Update();
    Rectangle GetCollisionRect();

    std::string_view GetSuggestedAction();

    int spriteSheetIndex = 0;
    Vector2 position = {};

    UtilitySystem utilitySystem;
    PetActions actions;
    PetNeeds needs;
};