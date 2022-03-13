#include "UtilitySystem/ActionBase.hpp"
#include "UtilitySystem/Blackboard.hpp"

ActionBase::ActionBase(Blackboard &blackboard) : _blackboard{&blackboard}
{

}

ActionBase::ActionBase(ActionBase &action)
{
 _blackboard = action._blackboard;

}

