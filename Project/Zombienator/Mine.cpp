#include "Mine.h"
#include "GameObjectFactory.h"
#include "MineBullet.h"
#include "SoundController.h"

Mine::Mine() : Weapon("assets/images/Mine.png")
{
	this->name = "Mine";
	this->delay = 100;
	//set damage in minebullet.cpp. If you set a mine, switch weapon, the on collide function gets the damage of current weapon.
	//this->damage = 5000;  // 1/5 of a zombie's health
	this->rounds = 10;
	this->maxRounds = 20;
	this->bulletType = "MineBullet";

	GameObjectFactory::Instance()->Register(bulletType, [](void) -> GameObject* { return new MineBullet(); });
}


Mine::~Mine()
{
}

void Mine::Fire()
{
	Weapon::Fire();
	if (rounds != 0) {
		MineBullet* b = GameObjectFactory::Instance()->CreateMineBullet(this->character);
		SoundController::GetInstance().PlaySound("assets/sounds/plantMine.wav", 0);
	}
	
}