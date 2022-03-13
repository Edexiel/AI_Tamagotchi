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
}                                           \
if (isSelected)                             \
    ImGui::SetItemDefaultFocus();           \
}

void SelectCurve(UtilityCurves::CurveSignature &currentCurve) {
    if (ImGui::BeginCombo("Function signature", "Select the curve")) {
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
        ImGui::PushStyleVar(ImGuiStyleVar_IndentSpacing, 5);

        ImGui::Text("FPS: %d", GetFPS());

        if (ImGui::CollapsingHeader("README", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::TextWrapped("This menu contains every information about the pet\n\n"
                        "The \"Stats\" Menu contains the pet current statistics and corresponding buttons to fullfill them\n"
                        "The \"Utility\" Menu contains the scores of the various utilities\n"
                        "The \"Gameplay values\" menu contains editors for the various utilities\n"
                        "The \"Curves Previewer\" is a helper menu to preview the utility curves without modifying the current ones");
        }

        if (ImGui::CollapsingHeader("Stats"))
        {
            ImGui::Indent();

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

            ImGui::Unindent();
        }

        if (ImGui::CollapsingHeader("Utility"))
        {
            ImGui::Indent();

            Blackboard& blackboard = app->pet.utilitySystem.GetBlackboard();

            ActionBase* actionSuggested = app->pet.utilitySystem.Evaluate();

            ImGui::Text("Suggested action: %s", actionSuggested->GetName().data());

            ImGui::Separator();

            for (auto utility : app->pet.utilitySystem._utilities)
            {
                ImGui::Text("%s: %f", utility->GetName().data(), utility->Evaluate(blackboard));
            }

            ImGui::Unindent();
        }

        if (ImGui::CollapsingHeader("Gameplay values"))
        {
            ImGui::Indent();

            UtilitySystem& utilitySystem = app->pet.utilitySystem;
            Blackboard& blackboard = utilitySystem.GetBlackboard();

            if (ImGui::CollapsingHeader("Utility System"))
            {
                ImGui::SliderFloat("Min Score Value", &utilitySystem._minScore, 0.f, 1.f);
                ImGui::SliderFloat("Max Score Value", &utilitySystem._maxScore, 0.f, 1.f);
                ImGui::Checkbox("Update Stats in Real Time", &app->pet.updateStats);
            }

            if (ImGui::CollapsingHeader("Utilities"))
            {
                ImGui::Indent();
                InspectUtilities();
                ImGui::Unindent();
            }

            if (ImGui::CollapsingHeader("Stat depleting rates"))
            {
                ImGui::Indent();
                ImGui::PushID("Rates");

                PetNeeds& petNeeds = app->pet.needs;

                for (auto& need : petNeeds.needRates)
                {
                    ImGui::SliderFloat(need.first, &need.second, 0.f, 1.f, "%.3f", ImGuiSliderFlags_Logarithmic);
                }

                ImGui::PopID();
                ImGui::Unindent();
            }

            ImGui::Unindent();
        }

        if (ImGui::CollapsingHeader("Curves Previewer"))
        {
            ImGui::Indent();

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

            ImGui::Unindent();
        }

        if (ImGui::CollapsingHeader("Animal"))
        {
            ImGui::Indent();

            ImGui::SliderInt("SpriteIndex", &app->pet.spriteSheetIndex, 0, (int)Animal::Size - 1);
            ImGui::LabelText("Animal", "%s", animalNames[app->pet.spriteSheetIndex]);

            ImGui::Unindent();
        }

        ImGui::PopStyleVar();
        ImGui::End();
    }
}

void DevMenu::InspectUtilities() {
    for (int i = 0; i < app->pet.utilitySystem._utilities.size(); i++)
    {
        ImGui::PushID(i);
        if (ImGui::CollapsingHeader(app->pet.utilitySystem._utilities[i]->GetName().data()))
        {
            UtilityInfo& utilityInfo = app->pet.utilitySystem._utilities[i]->_info;
            SelectCurve(utilityInfo.func);
            ImGui::SliderFloat("Second param", &utilityInfo.secondParam, -10, 10);
            ImGui::SliderFloat("Offset", &utilityInfo.offset, -1, 1);
            ImGui::Checkbox("One minus", &utilityInfo.oneMinus);

            float curveValue[1000];
            for (int i = 0; i < 1000; i++) {
                curveValue[i] = utilityInfo.Evaluate(i/1000.f);
            }

            ImGui::PlotLines("Curve", curveValue, 1000, 0, NULL, FLT_MAX, FLT_MAX, ImVec2(100, 50));
        }
        ImGui::PopID();
    }
}

void DevMenu::Init(App *_app) {
    this->app = _app;
}
