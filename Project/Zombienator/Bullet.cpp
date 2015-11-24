#pragma once
#include "Bullet.h"
#include "BehaviourFactory.h"

#include "DrawContainer.h"
#include "MoveContainer.h"
#include "CollideContainer.h"
#include "GameObjectContainer.h"

#include "MoveBehaviour.h"
#include "DrawBehaviour.h"
#include "CollideBehaviour.h"


void Bullet::Init(DrawContainer* dc, MoveContainer* mc, CollideContainer* cc, GameObjectContainer* goc)
{
	this->drawContainer = dc;
	this->moveContainer = mc;
	this->collideContainer = cc;
	this->gameObjectContainer = goc;
	this->gameObjectContainer->AddGameObject(this);
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}


void Bullet::SetDrawBehaviour(std::string name)
{
	this->drawBehaviour = BehaviourFactory::Instance()->CreateDrawBehaviour(name, this);
	if (drawBehaviour != nullptr) {
		drawBehaviour->SetGameObject(this);
		this->drawContainer->Add(drawBehaviour);
	}
}

void Bullet::SetMoveBehaviour(std::string name)
{
	this->moveBehaviour = BehaviourFactory::Instance()->CreateMoveBehaviour(name, this);
	if (moveBehaviour != nullptr) {
		moveBehaviour->SetGameObject(this);
		this->moveContainer->Add(moveBehaviour);
	}
}
void Bullet::SetCollideBehaviour(std::string name)
{
	this->collideBehaviour = BehaviourFactory::Instance()->CreateCollideBehaviour(name, this);
	if (collideBehaviour != nullptr) {
		collideBehaviour->SetGameObject(this);
		this->collideContainer->Add(collideBehaviour);
	}
}
