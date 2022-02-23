#pragma once

#include "devMenu.h"

class App {
public:
    App() = default;

    void Init();
    void Update();
    void Render();
    void Close();

private:
    DevMenu devMenu;
};

