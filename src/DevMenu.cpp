#include <string_view>
#include <string>
#include "DevMenu.h"
#include "Curves.h"

#include "raylib.h"
#include "raymath.h"
#include "AnimalSpriteSheet.h"

#include "App.h"

#include "PetStats.h"

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

#define STAT_SLIDER(statName)                       \
{                                                   \
    float stat = blackboard.GetValue(statName);     \
    ImGui::SliderFloat(statName, &stat, 0.f, 1.f);  \
    blackboard.SetValue(statName, stat);            \
}

void DevMenu::Update() {
    if (IsKeyPressed(KEY_F1)) {
        isOpen = !isOpen;
    }

    if (isOpen) {
        ImGui::Begin("Dev menu", &isOpen);

        ImGui::Text("FPS: %d", GetFPS());

        if (ImGui::CollapsingHeader("Animal"))
        {
            ImGui::SliderInt("SpriteIndex", &app->pet.spriteSheetIndex, 0, (int)Animal::Size - 1);
            ImGui::LabelText("Animal", "%s", animalNames[app->pet.spriteSheetIndex]);
        }

        if (ImGui::CollapsingHeader("Stats"))
        {
            Blackboard& blackboard = app->pet.utilitySystem.GetBlackboard();

            if (ImGui::Button("Feed")) {
                app->pet.actions.eat.Execute(blackboard);
            }
            ImGui::SameLine();
            STAT_SLIDER(PET_SATIETY);

            if (ImGui::Button("Clean")) {
                app->pet.actions.clean.Execute(blackboard);
            }
            ImGui::SameLine();
            STAT_SLIDER(PET_CLEANLINESS);

            if (ImGui::Button("Play")) {
                app->pet.actions.play.Execute(blackboard);
            }
            ImGui::SameLine();
            STAT_SLIDER(PET_SADNESS);

            if (ImGui::Button("Sleep")) {
                app->pet.actions.sleep.Execute(blackboard);
            }
            ImGui::SameLine();
            STAT_SLIDER(PET_SLEEPINESS);
        }

        if (ImGui::CollapsingHeader("Utility"))
        {
            Blackboard& blackboard = app->pet.utilitySystem.GetBlackboard();

            ActionBase* actionSuggested = app->pet.utilitySystem.Evaluate();

            ImGui::Text("Suggested action: %s", actionSuggested->GetName().data());

            for (auto utility : app->pet.utilitySystem._utilities)
            {
                ImGui::Text("%s: %f", utility->GetName().data(), utility->Evaluate(blackboard));
            }
        }

        if (ImGui::CollapsingHeader("Curves"))
        {
            static UtilityCurves::CurveSignature currentSignature = UtilityCurves::step;
            SelectCurve(currentSignature);

            static float secondParam = 1.0f;
            ImGui::SliderFloat("Second param", &secondParam, 0.0001, 10);

            static float offset = 0.0f;
            ImGui::SliderFloat("Offset", &offset, -1, 1);

            float curveValue[1000];
            for (int i = 0; i < 1000; i++) {
                curveValue[i] = currentSignature(i / 1000.f + offset, secondParam);
            }

            ImGui::PlotLines("Curve", curveValue, 1000, 0, NULL, FLT_MAX, FLT_MAX, ImVec2(400, 200));
        }


        ImGui::End();
    }
}

void DevMenu::Init(App *_app) {
    this->app = _app;
}
