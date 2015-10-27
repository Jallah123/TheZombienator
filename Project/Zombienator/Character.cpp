#include "Character.h"

#include "BehaviourFactory.h"
#include "AnimateBehaviour.h"
#include "DrawBehaviour.h"
#include "MoveBehaviour.h"
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"


Character::Character() : GameObject() 
{
	SetSpeed(1);
}

Character::~Character()
{
}

void Character::SetContainers(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, InputContainer* inputC)
{
	drawContainer = drawC;
	animateContainer = animC;
	moveContainer = moveC;
	inputContainer = inputC;
}

void Character::SetDrawBehaviour(std::string name)
{
	this->drawBehaviour = BehaviourFactory::Instance()->CreateDrawBehaviour(name, this);
	this->drawContainer->Add(drawBehaviour);
}

void Character::SetAnimateBehaviour(std::string name)
{
	this->animateBehaviour = BehaviourFactory::Instance()->CreateAnimateBehaviour(name, this);
	this->animateContainer->Add(animateBehaviour);
}

void Character::SetMoveBehaviour(std::string name)
{
	this->moveBehaviour = BehaviourFactory::Instance()->CreateMoveBehaviour(name, this);
	this->moveContainer->Add(moveBehaviour);
}

