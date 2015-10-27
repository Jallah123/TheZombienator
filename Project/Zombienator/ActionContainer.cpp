#pragma once
#include "BehaviourFactory.h"
#include "ActionContainer.h"
#include "ActionBehaviour.h"
#include "ShootActionBehaviour.h"
#include "InputContainer.h"
#include "KeyboardInputHandler.h"

ActionContainer::ActionContainer() : AbstractContainer()
{
	KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();
	this->inputContainer = kh.inputContainer;
	BehaviourFactory::Instance()->Register("ShootActionBehaviour", [](void) -> Behaviour* { return new ShootActionBehaviour(); });

}


ActionContainer::~ActionContainer()
{
}

void ActionContainer::Update(float dt)
{
	for (Behaviour* b : this->arr) {
		ActionBehaviour* ab = dynamic_cast<ActionBehaviour*>(b);
		ab->Update(dt);
	}
}
