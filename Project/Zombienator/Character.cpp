#include "Character.h"

#include "BehaviourFactory.h"

//Behaviours
#include "AnimateBehaviour.h"
#include "DrawBehaviour.h"
#include "MoveBehaviour.h"
#include "ActionBehaviour.h"
#include "CollideBehaviour.h"

//Containers
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "ActionContainer.h"
#include "CollideContainer.h"
#include "CharacterContainer.h"

Character::Character() : GameObject()
{
	SetSpeed(1);
}

Character::~Character()
{
	std::vector<ActionBehaviour*>::reverse_iterator it;
	for (it = actionBehaviours.rbegin(); it != actionBehaviours.rend(); ++it)
		delete *it;

	actionBehaviours.clear();
}

void Character::TakeHit(int damage)
{
	health -= damage;
	if (health <= 0)
		Remove();
}


void Character::SetContainers(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, InputContainer * inputC, ActionContainer * actionC, CollideContainer * collideC, CharacterContainer * characterC)
{
	drawContainer = drawC;
	animateContainer = animC;
	moveContainer = moveC;
	inputContainer = inputC;
	actionContainer = actionC;
	collideContainer = collideC;
	characterContainer = characterC;
}

void Character::SetDrawBehaviour(std::string name)
{
	this->drawBehaviour = BehaviourFactory::Instance()->CreateDrawBehaviour(name, this);
	if (drawBehaviour != nullptr)
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

void Character::SetCollideBehaviour(std::string name)
{
	this->collideBehaviour = BehaviourFactory::Instance()->CreateCollideBehaviour(name, this);
	if (collideBehaviour != nullptr)
		this->collideContainer->Add(collideBehaviour);
}

void Character::SetMap(Map * m)
{
	map = m;
	collisionLayer = m->GetObjectLayer("Collision");
}

void Character::Remove()
{
	drawBehaviour->CanRemove(true);
	animateBehaviour->CanRemove(true);
	moveBehaviour->CanRemove(true);
	collideBehaviour->CanRemove(true);
	for (const auto& ab : actionBehaviours) {
		ab->CanRemove(true);
	}
	this->characterContainer->Remove(this);
}

