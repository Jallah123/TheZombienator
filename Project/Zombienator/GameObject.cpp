#pragma once
#include "GameObject.h"

//Factories
#include "BehaviourFactory.h"
#include "TextureFactory.h"

//Behaviours
#include "AnimateBehaviour.h"
#include "DrawBehaviour.h"
#include "MoveBehaviour.h"
#include "CollideBehaviour.h"
#include "ActionBehaviour.h"

//Containers
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "CollideContainer.h"
#include "GameObjectContainer.h"
#include "ActionContainer.h"


GameObject::GameObject()
{
}

GameObject::GameObject(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	:drawContainer{drawC}, animateContainer{animC}, moveContainer{moveC}, collideContainer{collideC}, actionContainer{actionC}, gameObjectContainer{gameObjectC}
{
}

GameObject::~GameObject()
{
	std::vector<ActionBehaviour*>::reverse_iterator it;
	for (it = actionBehaviours.rbegin(); it != actionBehaviours.rend(); ++it)
		delete *it;

	actionBehaviours.clear();

	delete texture;
}

void GameObject::SetImage(std::string path)
{
	texture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void GameObject::SetSize(int w, int h)
{
	this->width = w;
	this->height = h;
	sourceRect.w = w;
	sourceRect.h = h;
	collRect.w = w;
	collRect.h = h / 2;
}

void GameObject::SetPosition(float x, float y)
{
	destRect = { (int)(x + 0.5f), (int)(y + 0.5f), width, height };
	posX = x;
	posY = y;
	collRect.x = destRect.x;
	collRect.y = destRect.y + collRect.h;
}

void GameObject::SetDrawBehaviour(std::string name)
{
	this->drawBehaviour = BehaviourFactory::Instance()->CreateDrawBehaviour(name, this);
	if (drawBehaviour != nullptr)
		this->drawContainer->Add(drawBehaviour);
}

void GameObject::SetAnimateBehaviour(std::string name)
{
	this->animateBehaviour = BehaviourFactory::Instance()->CreateAnimateBehaviour(name, this);
	if (animateBehaviour != nullptr)
		this->animateContainer->Add(animateBehaviour);
}

void GameObject::SetMoveBehaviour(std::string name)
{
	this->moveBehaviour = BehaviourFactory::Instance()->CreateMoveBehaviour(name, this);
	if (moveBehaviour != nullptr)
		this->moveContainer->Add(moveBehaviour);
}

void GameObject::SetActionBehaviour(std::string name)
{
	ActionBehaviour* a = BehaviourFactory::Instance()->CreateActionBehaviour(name, this);
	if (a == nullptr) return;
	this->actionBehaviours.push_back(a);
	this->actionContainer->Add(a);
}

void GameObject::SetCollideBehaviour(std::string name)
{
	this->collideBehaviour = BehaviourFactory::Instance()->CreateCollideBehaviour(name, this);
	if (collideBehaviour != nullptr)
		this->collideContainer->Add(collideBehaviour);
}

void GameObject::Remove()
{
	if (drawBehaviour != nullptr) drawBehaviour->CanRemove(true);
	if (animateBehaviour != nullptr) animateBehaviour->CanRemove(true);
	if (moveBehaviour != nullptr) moveBehaviour->CanRemove(true);
	if (collideBehaviour != nullptr) collideBehaviour->CanRemove(true);

	for (const auto& ab : actionBehaviours) {
		if (ab != nullptr)
			ab->CanRemove(true);
	}

	this->gameObjectContainer->Remove(this);
}
