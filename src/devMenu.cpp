#include "devMenu.h"
#include "raylib.h"

void DevMenu::Update() {
    if (IsKeyPressed(KEY_F1)) {
        isOpen = !isOpen;
    }
}

void DevMenu::Render() {
    if (isOpen) {
        ImGui::Begin("Dev menu", &isOpen);

        ImGui::Text("Salut");

        ImGui::End();
    }
}