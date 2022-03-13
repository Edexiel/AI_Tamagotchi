#pragma once

#include "imgui.h"

class App;
class DevMenu {
public:
    void Init(App* _app);
    void Update();
    bool isOpen = false;
private:
    App* app;

    void InspectUtilities();
};