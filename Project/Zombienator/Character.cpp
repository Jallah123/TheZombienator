#include "Character.h"

#include "BehaviourFactory.h"

//Behaviours
#include "AnimateBehaviour.h"
#include "DrawBehaviour.h"
#include "MoveBehaviour.h"
#include "ActionBehaviour.h"

//Containers
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "ActionContainer.h"

Character::Character() : GameObject() 
{
	SetSpeed(1);
}

Character::~Character()
{
}

void Character::SetContainers(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, InputContainer* inputC, ActionContainer* actionC)
{
	drawContainer = drawC;
	animateContainer = animC;
	moveContainer = moveC;
	inputContainer = inputC;
	actionContainer = actionC;
}

void Character::SetDrawBehaviour(std::string name)
{
	this->drawBehaviour = BehaviourFactory::Instance()->CreateDrawBehaviour(name, this);
	if(drawBehaviour != nullptr)
		this->drawContainer->Add(drawBehaviour);
}

void Character::SetAnimateBehaviour(std::string name)
{
	this->animateBehaviour = BehaviourFactory::Instance()->CreateAnimateBehaviour(name, this);
	if (animateBehaviour != nullptr)
		this->animateContainer->Add(animateBehaviour);
}

void Character::SetMoveBehaviour(std::string name)
{
	this->moveBehaviour = BehaviourFactory::Instance()->CreateMoveBehaviour(name, this);
	if (moveBehaviour != nullptr)
		this->moveContainer->Add(moveBehaviour);
}

void Character::SetActionBehaviour(std::string name)
{
	ActionBehaviour* a = BehaviourFactory::Instance()->CreateActionBehaviour(name, this);
	if (moveBehaviour == nullptr) return;
	this->actionBehaviours.push_back(a);
	this->actionContainer->Add(a);
}

