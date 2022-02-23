#include "raylib.h"
#include "raymath.h"

#include "imgui.h"
#include "rlImGui.h"

#include "pet.h"
#include "app.h"

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