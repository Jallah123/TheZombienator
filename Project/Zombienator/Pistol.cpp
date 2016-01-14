#pragma once
#include "Pistol.h"
#include <limits>
#include "NormalBullet.h"
#include "BehaviourFactory.h"
#include "GameObjectFactory.h"
#include "SoundController.h"

Pistol::Pistol() : Weapon("Pistol", INT_MAX, INT_MAX, 80, 20, "bullet", SDL_Rect{222, 214, 262, 165})
{
	GameObjectFactory::Instance()->Register(bulletType, [](void) -> GameObject* { return new NormalBullet(); });
}


Pistol::~Pistol()
{
}

void Pistol::Fire()
{
	Weapon::Fire();
	NormalBullet* b = GameObjectFactory::Instance()->CreateNormalBullet(this->character);
	SoundController::GetInstance().PlaySound("assets/sounds/cg1.flac", 0);
	this->rounds = maxRounds;
}


