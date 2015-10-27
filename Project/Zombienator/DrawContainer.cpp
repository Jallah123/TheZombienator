#pragma once
#include "DrawBehaviour.h"
#include "DrawContainer.h"
#include "BehaviourFactory.h"
#include "NormalBulletDrawBehaviour.h"
#include "CharacterDrawBehaviour.h"

DrawContainer::DrawContainer()
{
	//Register all Draw behaviours in the behaviour factory
	BehaviourFactory::Instance()->Register("CharacterDrawBehaviour", [](void) -> Behaviour* { return new CharacterDrawBehaviour(); });
	BehaviourFactory::Instance()->Register("NormalBulletDrawBehaviour", [](void) -> Behaviour* { return new NormalBulletDrawBehaviour(); });
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
