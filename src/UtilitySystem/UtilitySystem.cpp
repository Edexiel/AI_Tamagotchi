#include "UtilitySystem/UtilitySystem.hpp"

#include "UtilitySystem/UtilityBase.hpp"


UtilitySystem::UtilitySystem(const std::string_view &name, float maxScore, ActionBase *defaultAction) : _name(name),
                                                                                                        _maxScore(
                                                                                                                maxScore),
                                                                                                        _defaultAction(
                                                                                                                defaultAction)
{}

ActionBase* UtilitySystem::Evaluate()
{
    float bestScore = 0.05f;
    ActionBase *action = _defaultAction;

    for (const auto &utility: _utilities) {
        float score = utility->Evaluate(blackboard);

        if (score == _maxScore) {
            action = utility->GetAction();
            break;

        }
        if (score > bestScore) {
            bestScore = score;
            action = utility->GetAction();
        }

    }
    return action;
}



