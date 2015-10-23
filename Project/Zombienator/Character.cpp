#include "Character.h"



Character::Character() : GameObject() 
{
	SetSpeed(1);
}

Character::~Character()
{
}

void Character::SetContainers(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC)
{
	drawContainer = drawC;
	animateContainer = animC;
	moveContainer = moveC;
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

