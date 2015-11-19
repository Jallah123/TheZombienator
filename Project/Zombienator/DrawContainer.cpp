#pragma once
#include "DrawBehaviour.h"
#include "DrawContainer.h"
#include "BehaviourFactory.h"
#include "NormalBulletDrawBehaviour.h"
#include "MovingBulletDrawBehaviour.h"
#include "CharacterDrawBehaviour.h"
#include "Bullet.h"

DrawContainer::DrawContainer()
{
	//Register all Draw behaviours in the behaviour factory
	BehaviourFactory::Instance()->Register("CharacterDrawBehaviour", [](void) -> Behaviour* { return new CharacterDrawBehaviour(); });
	BehaviourFactory::Instance()->Register("NormalBulletDrawBehaviour", [](void) -> Behaviour* { return new NormalBulletDrawBehaviour(); });
	BehaviourFactory::Instance()->Register("MovingBulletDrawBehaviour", [](void) -> Behaviour* { return new MovingBulletDrawBehaviour(); });
}


DrawContainer::~DrawContainer()
{
}


void DrawContainer::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	if (this->arr.empty()) return;//Do nothing on empty
	
	for (Behaviour* i : this->arr) {
		DrawBehaviour* db = dynamic_cast<DrawBehaviour*>(i);
		
		//Draw each Behaviour
		db->Draw(dt, ren, XOffset, YOffset);
		if (NormalBulletDrawBehaviour* b = dynamic_cast<NormalBulletDrawBehaviour*>(db)) {
			if (Bullet* bullet = dynamic_cast<Bullet*>(b->GetGameObject())) {
				if (bullet->GetLifeTime() <= 0) {
					i->CanRemove(true);
				}
			}
		}
		if (i->CanBeRemove()) arrRemove.push_back(i);
	}
	RemoveAll();
}
