#include <string>
#include "DevMenu.h"
#include "Curves.h"

#include "raylib.h"
#include "raymath.h"
#include "AnimalSpriteSheet.h"

#include "App.h"

#define SELECT_FUNCTION(currentfunc, func)  \
{                                           \
bool isSelected = (currentfunc == func);    \
if (ImGui::Selectable(#func, isSelected)) { \
    currentfunc = func;                     \
    funcName = #func;                        \
}                                           \
if (isSelected)                             \
    ImGui::SetItemDefaultFocus();           \
}

void SelectCurve(UtilityCurves::CurveSignature &currentCurve) {
    static std::string funcName;
    if (ImGui::BeginCombo("Function signature", funcName.c_str())) {
        SELECT_FUNCTION(currentCurve, UtilityCurves::step);
        SELECT_FUNCTION(currentCurve, UtilityCurves::linear);
        SELECT_FUNCTION(currentCurve, UtilityCurves::exponential);
        SELECT_FUNCTION(currentCurve, UtilityCurves::sigmoid);
        ImGui::EndCombo();
    }
}

void DevMenu::Update() {
    if (IsKeyPressed(KEY_F1)) {
        isOpen = !isOpen;
    }

    if (isOpen) {
        ImGui::Begin("Dev menu", &isOpen);

        ImGui::Text("Salut");

        ImGui::SliderInt("SpriteIndex", &app->pet.spriteSheetIndex, 0, (int)Animal::Size - 1);
        ImGui::LabelText("Animal", "%s", animalNames[app->pet.spriteSheetIndex]);

        static UtilityCurves::CurveSignature currentSignature = UtilityCurves::step;
        SelectCurve(currentSignature);

        static float secondParam = 1.0f;
        ImGui::SliderFloat("Second param", &secondParam, 0.0001, 10);

        float curveValue[1000];
        for (int i = 0; i < 1000; i++) {
            curveValue[i] = currentSignature(i / 1000.f, secondParam);
        }

        ImGui::PlotLines("Curve", curveValue, 1000, 0, NULL, FLT_MAX, FLT_MAX, ImVec2(400, 200));
        ImGui::End();
    }
}

void DevMenu::Init(App *_app) {
    this->app = _app;
}
