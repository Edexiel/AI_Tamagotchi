#pragma once

#include "imgui.h"

class App;
class DevMenu {
public:
    void Init(App* _app);
    void Update();
    void Render();
    bool isOpen = false;
private:
    App* app;
};