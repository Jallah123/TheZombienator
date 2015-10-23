#pragma once
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
	if (this->arr.empty()) return;//Do nothing on empty
	for (Behaviour* i : this->arr) {
		DrawBehaviour* db = dynamic_cast<DrawBehaviour*>(i);
		
		//Draw each Behaviour
		db->Draw(dt, ren);
	}
}
