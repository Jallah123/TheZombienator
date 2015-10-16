#include "Character.h"



Character::Character() : GameObject() 
{
}

Character::~Character()
{
}

void Character::SetContainers(DrawContainer * drawC, AnimateContainer * animC)
{
	drawContainer = drawC;
	animateContainer = animC;
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
