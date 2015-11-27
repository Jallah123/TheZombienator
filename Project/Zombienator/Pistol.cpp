#pragma once
#include "Pistol.h"
#include <limits>
#include <iostream>
#include "NormalBullet.h"
#include "BehaviourFactory.h"
#include "GameObjectFactory.h"

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
	NormalBullet* b = GameObjectFactory::Instance()->CreateNormalBullet(this->character);
}


