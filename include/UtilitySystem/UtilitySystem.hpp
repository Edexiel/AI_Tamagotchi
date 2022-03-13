#pragma once

#include <vector>
#include <memory>
#include <string_view>

#include "UtilitySystem/ActionBase.hpp"
#include "Blackboard.hpp"
#include "UtilityBase.hpp"

class DevMenu;

class UtilitySystem {
    friend DevMenu;
private:
    std::string_view _name;
    float _maxScore;

    ActionBase *_defaultAction;

    std::vector<UtilityBase *> _utilities;

    Blackboard blackboard;

public:

    UtilitySystem(const std::string_view &name, float maxScore, ActionBase *defaultAction = nullptr);

    template<class UtilityType, class ActionType>
    void AddUtility(std::string_view name, ActionType* action) {
        _utilities.push_back((UtilityBase *) (new UtilityType(name, (ActionBase*)action)));
    }

    ActionBase* Evaluate();

    const std::string_view &GetName() const {
        return _name;
    }

    ActionBase *GetDefaultAction() const {
        return _defaultAction;
    }

    void SetDefaultAction(ActionBase *defaultAction) {
        _defaultAction = defaultAction;
    }

    Blackboard &GetBlackboard() { return blackboard; };

};