#pragma once

#include "DevMenu.h"

#include "raylib.h"

class App {
    friend DevMenu;
public:
    App() = default;

    void Init();

    void Update();

    void Render();

    void Close();

private:
    DevMenu devMenu;

    bool buttonHovered = false;
    Rectangle btnBounds;
    Texture2D spriteSheet;
    int animalSpriteIndex;
};

