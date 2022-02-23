#pragma once

#include "raylib.h"

class Pet {
public:
    void Draw(Texture &spriteSheet);

    Rectangle GetCollisionRect();

    int spriteSheetIndex = 0;
    Vector2 position = {};
};