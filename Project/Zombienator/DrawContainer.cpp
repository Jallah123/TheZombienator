#pragma once
#include "DrawBehaviour.h"
#include "DrawContainer.h"
#include "BehaviourFactory.h"
#include "NormalBulletDrawBehaviour.h"
#include "MovingBulletDrawBehaviour.h"
#include "NonMovingBulletDrawBehaviour.h"
#include "CharacterDrawBehaviour.h"
#include "SimpleDrawBehaviour.h"
#include "Bullet.h"
#include <algorithm>
#include "GameObject.h"
DrawContainer::DrawContainer()
{
	//Register all Draw behaviours in the behaviour factory
	BehaviourFactory::Instance()->Register("CharacterDrawBehaviour", [](void) -> Behaviour* { return new CharacterDrawBehaviour(); });
	BehaviourFactory::Instance()->Register("NormalBulletDrawBehaviour", [](void) -> Behaviour* { return new NormalBulletDrawBehaviour(); });
	BehaviourFactory::Instance()->Register("MovingBulletDrawBehaviour", [](void) -> Behaviour* { return new MovingBulletDrawBehaviour(); });
	BehaviourFactory::Instance()->Register("NonMovingBulletDrawBehaviour", [](void) -> Behaviour* { return new NonMovingBulletDrawBehaviour(); });
	BehaviourFactory::Instance()->Register("SimpleDrawBehaviour", [](void) -> Behaviour* { return new SimpleDrawBehaviour(); });
}


DrawContainer::~DrawContainer()
{
}


void DrawContainer::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	if (arr.empty()) return;//Do nothing on empty

	Sort_zIndex();
	for (auto itr = arr.begin(); itr != arr.end();)
	{
		DrawBehaviour* db = dynamic_cast<DrawBehaviour*>(*itr);
		db->Draw(dt, ren, XOffset, YOffset);

		if (db->CanBeRemove())
			itr = Remove(db);
		else
			++itr;
	}
}

void DrawContainer::Sort_zIndex()
{
	std::sort(arr.begin(), arr.end(), [](Behaviour* a, Behaviour* b) { return a->GetGameObject()->getPosY() < b->GetGameObject()->getPosY(); });
}
