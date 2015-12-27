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
	if (arr.empty()) return;
	
	for (auto itr = arr.begin(); itr != arr.end();)
	{
		ActionBehaviour* ab = dynamic_cast<ActionBehaviour*>(*itr);
		ab->Update(dt);

		if (ab->CanBeRemove())
			itr = Remove(ab);
		else
			++itr;
	}
}
