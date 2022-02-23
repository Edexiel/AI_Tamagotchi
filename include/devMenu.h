#pragma once

#include "imgui.h"

class DevMenu {
public:
    void Update();
    void Render();
    bool isOpen = false;
};