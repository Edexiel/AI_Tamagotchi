#pragma once

#include "DevMenu.h"

#include "raylib.h"
#include "Pet.h"

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

    Texture2D spriteSheet;
    Pet pet;
};

