#include "MachineGun.h"
#include "GameObjectFactory.h"
#include "MachineGunBullet.h"
#include "SoundController.h"

MachineGun::MachineGun() 
	: Weapon("MachineGun", 20, 200, 20, 20, "MachineGunBullet", SDL_Rect{ 580, 431, 282, 186 })
{
	GameObjectFactory::Instance()->Register(bulletType, [](void) -> GameObject* { return new MachineGunBullet(); });
}


MachineGun::~MachineGun()
{
}

void MachineGun::Fire()
{
	Weapon::Fire();
	if (rounds != 0) {
		MachineGunBullet* b = GameObjectFactory::Instance()->CreateMachineGunBullet(this->character);
		SoundController::GetInstance().PlaySound("assets/sounds/pistol.flac", 0);
	}
	else {
		SoundController::GetInstance().PlaySound("assets/sounds/gun-empty.flac", 0);
	}
}