#pragma once
#include "BehaviourFactory.h"
#include "ActionContainer.h"
#include "ActionBehaviour.h"
#include "ShootActionBehaviour.h"
#include "SwitchWeaponActionBehaviour.h"
#include "Shoot2ActionBehaviour.h"
#include "SwitchWeapon2ActionBehaviour.h"

ActionContainer::ActionContainer() : AbstractContainer()
{
	BehaviourFactory::Instance()->Register("ShootActionBehaviour", [](void) -> Behaviour* { return new ShootActionBehaviour(); });
	BehaviourFactory::Instance()->Register("SwitchWeaponActionBehaviour", [](void) -> Behaviour* { return new SwitchWeaponActionBehaviour(); });
	BehaviourFactory::Instance()->Register("Shoot2ActionBehaviour", [](void) -> Behaviour* { return new Shoot2ActionBehaviour(); });
	BehaviourFactory::Instance()->Register("SwitchWeapon2ActionBehaviour", [](void) -> Behaviour* { return new SwitchWeapon2ActionBehaviour(); });
}


ActionContainer::~ActionContainer()
{
}

void ActionContainer::Update(float dt)
{
	if (arr.empty()) return;
	
	for (Behaviour* b : this->arr) {
		ActionBehaviour* ab = dynamic_cast<ActionBehaviour*>(b);
		ab->Update(dt);
		if (ab->CanBeRemove()) arrRemove.push_back(ab);
	}
	RemoveAll();
}
