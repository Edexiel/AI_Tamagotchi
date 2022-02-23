#include "app.h"
#include "devMenu.h"

#include "raylib.h"
#include "rlImGui.h"

void App::Init() {
    int screenWidth = 1900;
    int screenHeight = 900;

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(screenWidth, screenHeight, "Kintama aka le projet couille");
    //SetTargetFPS(120);
    SetupRLImGui(true);
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
}

void App::Update() {
    devMenu.Update();
}

void App::Render() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    BeginRLImGui();

    DrawText("F1 to open dev menu", 10, 10, 36, Color{255, 0, 255, 255});
    devMenu.Render();
    EndRLImGui();
    EndDrawing();
}

void App::Close() {
    ShutdownRLImGui();
    CloseWindow();
}
