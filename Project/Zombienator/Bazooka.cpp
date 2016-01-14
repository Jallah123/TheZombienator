#include "Bazooka.h"
#include "GameObjectFactory.h"
#include "BazookaBullet.h"
#include "SoundController.h"

Bazooka::Bazooka()
	: Weapon("Bazooka", 10, 20, 200, 100, "BazookaBullet", SDL_Rect{ 1064, 1022, 708, 218 })
{
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
		SoundController::GetInstance().PlaySound("assets/sounds/bazooka.flac", 0);
	}
	else {
		SoundController::GetInstance().PlaySound("assets/sounds/gun-empty.flac", 0);
	}
}