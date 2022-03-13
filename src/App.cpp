#include "App.h"
#include "DevMenu.h"

#include "raylib.h"
#include "raymath.h"
#include "rlImGui.h"

#include "imgui.h"

void App::Init() {
    int screenWidth = 1200;
    int screenHeight = 720;

    SetTraceLogLevel(LOG_DEBUG);
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(screenWidth, screenHeight, "Kintama");
    //SetTargetFPS(120);
    SetupRLImGui(true);
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;

    devMenu.Init(this);

    spriteSheet = LoadTexture("assets/animals.png");
    GenTextureMipmaps(&spriteSheet);

    pet.position = {screenWidth / 2.0f, screenHeight / 2.0f};
}

void App::Update() {

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), pet.GetCollisionRect())) {
        pet.position = Vector2Add(pet.position, GetMouseDelta());
    }

    pet.Update();

    DrawText(pet.GetSuggestedAction().data(), pet.position.x - 100.f, pet.position.y - 100.f, 24, MAGENTA);

    BeginDrawing();
    ClearBackground(DARKGRAY);

    BeginRLImGui();

    DrawText("F1 to open dev menu", 10, 10, 24, Color{255, 0, 255, 255});
    devMenu.Update();
    pet.Draw(spriteSheet);

    EndRLImGui();
    EndDrawing();
}

void App::Close() {

    UnloadTexture(spriteSheet);
    ShutdownRLImGui();
    CloseWindow();
}
