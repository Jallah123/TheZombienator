#include "Mine.h"
#include "GameObjectFactory.h"
#include "MineBullet.h"
#include "SoundController.h"

Mine::Mine() 
	: Weapon("Mine", 10, 20, 100, 80, "MineBullet", SDL_Rect{ 862, 214, 126, 68 })
{
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