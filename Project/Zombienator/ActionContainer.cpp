#pragma once
#include "BehaviourFactory.h"
#include "ActionContainer.h"
#include "ActionBehaviour.h"
#include "ShootActionBehaviour.h"
#include "SwitchWeaponActionBehaviour.h"

ActionContainer::ActionContainer() : AbstractContainer()
{
	BehaviourFactory::Instance()->Register("ShootActionBehaviour", [](void) -> Behaviour* { return new ShootActionBehaviour(); });
	BehaviourFactory::Instance()->Register("SwitchWeaponActionBehaviour", [](void) -> Behaviour* { return new SwitchWeaponActionBehaviour(); });
}


ActionContainer::~ActionContainer()
{
}

void ActionContainer::Update(float dt)
{
	for (Behaviour* b : this->arr) {
		ActionBehaviour* ab = dynamic_cast<ActionBehaviour*>(b);
		ab->Update(dt);
		if (ab->CanBeRemove()) arrRemove.push_back(ab);
	}
	RemoveAll();
}
