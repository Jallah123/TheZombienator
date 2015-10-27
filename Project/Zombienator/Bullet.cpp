#pragma once
#include "Bullet.h"
#include "BehaviourFactory.h"

#include "DrawContainer.h"
#include "MoveContainer.h"

#include "MoveBehaviour.h"
#include "DrawBehaviour.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::SetContainers(DrawContainer * drawC, MoveContainer * moveC)
{
	this->drawContainer = drawC;
	this->moveContainer = moveC;
}

void Bullet::SetDrawBehaviour(std::string name)
{
	this->drawBehaviour = BehaviourFactory::Instance()->CreateDrawBehaviour(name, this);
	if (drawBehaviour != nullptr)
		this->drawContainer->Add(drawBehaviour);
}

void Bullet::SetMoveBehaviour(std::string name)
{
	this->moveBehaviour = BehaviourFactory::Instance()->CreateMoveBehaviour(name, this);
	if (moveBehaviour != nullptr)
		this->moveContainer->Add(moveBehaviour);
}

