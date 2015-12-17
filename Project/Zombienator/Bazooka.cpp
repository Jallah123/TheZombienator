#include "Bazooka.h"
#include "GameObjectFactory.h"
#include "BazookaBullet.h"
#include "SoundController.h"

Bazooka::Bazooka() : Weapon("assets/images/Bazooka.png")
{
	this->name = "Bazooka";
	this->delay = 200;
	this->damage = 100;  // 1/5 of a zombie's health
	this->rounds = 20;
	this->maxRounds = 100;
	this->bulletType = "BazookaBullet";
	GameObjectFactory::Instance()->Register(bulletType, [](void) -> GameObject* { return new BazookaBullet(); });
}


Bazooka::~Bazooka()
{
}

void Bazooka::Fire()
{
	Weapon::Fire();
	if (rounds != 0) {
		BazookaBullet* b = GameObjectFactory::Instance()->CreateBazookaBullet(this->character);
		SoundController::GetInstance().PlaySound("assets/sounds/bazooka.wav", 0);
	}
	else {
		SoundController::GetInstance().PlaySound("assets/sounds/gun-empty.wav", 0);
	}
}