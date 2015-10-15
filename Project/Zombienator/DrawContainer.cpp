#pragma once
#include "iostream"
#include "DrawBehaviour.h"
#include "DrawContainer.h"
#include "BehaviourFactory.h"


DrawContainer::DrawContainer()
{
	//Register all Draw behaviours in the behaviour factory
	BehaviourFactory::Instance()->Register("DrawBehaviour", [](void) -> Behaviour* { return new DrawBehaviour(); });
}


DrawContainer::~DrawContainer()
{
}


void DrawContainer::Draw(float dt, SDL_Renderer & ren)
{
	std::cout << arr.size() << " DrawContainer size" << std::endl;
	if (this->arr.empty()) return;//Do nothing on empty
	for (Behaviour* i : this->arr) {
		DrawBehaviour* db = (DrawBehaviour*)&i;
		//Draw each Behaviour
		db->Draw(dt, ren);
	}
}
