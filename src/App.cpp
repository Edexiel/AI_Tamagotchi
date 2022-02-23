#include "App.h"
#include "DevMenu.h"

#include "raylib.h"
#include "rlImGui.h"

#include "AnimalSpriteSheet.h"

void App::Init() {
    int screenWidth = 1900;
    int screenHeight = 900;

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(screenWidth, screenHeight, "Kintama aka le projet couille");
    //SetTargetFPS(120);
    SetupRLImGui(true);
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;

    devMenu.Init(this);

    btnBounds = Rectangle{
        screenWidth / 2.0f,
        screenHeight / 2.0f,
        50,
        50,
    };

    spriteSheet = LoadTexture("assets/animals.png");
    GenTextureMipmaps(&spriteSheet);
    SetTextureFilter(spriteSheet, TEXTURE_FILTER_TRILINEAR);
}

void App::Update() {
    devMenu.Update();

    buttonHovered = CheckCollisionPointRec(GetMousePosition(), btnBounds);
}

void App::Render() {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    BeginRLImGui();

    DrawText("F1 to open dev menu", 10, 10, 36, Color{255, 0, 255, 255});
    devMenu.Render();

    DrawRectangleRec(btnBounds, (buttonHovered) ? MAGENTA : GREEN);


    Rectangle spriteInfo{animalSpriteInfos[animalSpriteIndex][0], animalSpriteInfos[animalSpriteIndex][1], animalSpriteInfos[animalSpriteIndex][2], animalSpriteInfos[animalSpriteIndex][3]};

    DrawTextureRec(spriteSheet, spriteInfo, Vector2 { (GetScreenWidth() - spriteInfo.width) / 2.0f, (GetScreenHeight() - spriteInfo.height) / 2.0f}, WHITE);
    EndRLImGui();
    EndDrawing();
}

void App::Close() {
    ShutdownRLImGui();
    CloseWindow();
}
