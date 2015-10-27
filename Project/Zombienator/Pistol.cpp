#pragma once
#include "Pistol.h"
#include <limits>
#include <iostream>
#include "BulletFactory.h"
#include "NormalBullet.h"

Pistol::Pistol() : Weapon()
{
	this->rounds = INT_MAX;
	this->delay = 20;
	this->damage = 20;  // 1/5 of a zombie's health
	this->bulletType = "bullet";
	BulletFactory::Instance()->Register(bulletType, [](void) -> Bullet* { return new NormalBullet(); });
}


Pistol::~Pistol()
{
}

void Pistol::Fire()
{
	std::cout << "FIRE MI PISTOL ARR" <<  std::endl;
	BulletFactory::Instance()->CreateNormalBullet(this->character);
}


