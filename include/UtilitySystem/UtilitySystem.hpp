#pragma once

#include <vector>
#include <memory>
#include <string_view>

#include "UtilitySystem/ActionBase.hpp"

class UtilitySystem
{
private:
    std::string_view _name;
    float _maxScore;

    ActionBase *_defaultAction;

    std::vector<std::unique_ptr<class UtilityBase>> _utilities;

public:

    UtilitySystem(const std::string_view &name, float maxScore, ActionBase &defaultAction);

    UtilityBase *AddUtility(UtilityBase &&utility);

    ActionBase &Evaluate();

    const std::string_view &GetName() const;

    ActionBase &GetDefaultAction() const;

    void SetDefaultAction(ActionBase &defaultAction);

};