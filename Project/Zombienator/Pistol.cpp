#pragma once
#include "Pistol.h"
#include <limits>
#include <iostream>
#include "NormalBullet.h"
#include "BehaviourFactory.h"
#include "GameObjectFactory.h"
#include "SoundController.h"

Pistol::Pistol() : Weapon("assets/images/Pistol.png")
{
	this->name = "Pistol";
	this->rounds = INT_MAX;
	this->delay = 80;
	this->damage = 20;  // 1/5 of a zombie's health
	this->bulletType = "bullet";
	GameObjectFactory::Instance()->Register(bulletType, [](void) -> GameObject* { return new NormalBullet(); });
}


Pistol::~Pistol()
{
}

void Pistol::Fire()
{
	Weapon::Fire();
	NormalBullet* b = GameObjectFactory::Instance()->CreateNormalBullet(this->character);
	SoundController::GetInstance().PlaySound("assets/sounds/cg1.wav", 0);
	this->rounds = INT_MAX;
}


