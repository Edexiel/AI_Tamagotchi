#include "raylib.h"
#include "raymath.h"

#include "imgui.h"
#include "rlImGui.h"

#include "App.h"

int main(int argc, char* argv[])
{
    App app;

    app.Init();

    while (!WindowShouldClose())
    {
        app.Update();
    }
    app.Close();

    return 0;
}