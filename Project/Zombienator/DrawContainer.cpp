#pragma once
#include "DrawBehaviour.h"
#include "DrawContainer.h"
#include "BehaviourFactory.h"
#include "NormalBulletDrawBehaviour.h"
#include "CharacterDrawBehaviour.h"
#include "Bullet.h"

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
	std::vector<NormalBulletDrawBehaviour*> bulletsToRemove;
	for (Behaviour* i : this->arr) {
		DrawBehaviour* db = dynamic_cast<DrawBehaviour*>(i);
		
		//Draw each Behaviour
		db->Draw(dt, ren);
		if (NormalBulletDrawBehaviour* b = dynamic_cast<NormalBulletDrawBehaviour*>(db)) {
			if (Bullet* bullet = dynamic_cast<Bullet*>(b->GetGameObject())) {
				if (bullet->GetLifeTime() <= 0) {
					bulletsToRemove.push_back(b);
				}
			}
		}
	}
	for each (auto& behaviour in bulletsToRemove)
	{
		Remove(behaviour);
	}
}
