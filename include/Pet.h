#pragma once

#include "raylib.h"
#include "UtilitySystem/UtilitySystem.hpp"
#include "PetActions.h"
#include "PetStats.h"

class Pet {
public:
    Pet();

    void Draw(Texture &spriteSheet,Texture& emojisheet);

    void Update();
    Rectangle GetCollisionRect();

    ActionBase* GetAction();
    std::string_view GetSuggestedAction();
    Emoji GetSuggestedEmoji();

    int spriteSheetIndex = 0;
    Vector2 position = {};

    UtilitySystem utilitySystem;
    PetActions actions;
    PetNeeds needs;
};