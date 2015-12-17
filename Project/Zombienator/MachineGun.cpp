#include "MachineGun.h"
#include "GameObjectFactory.h"
#include "MachineGunBullet.h"
#include "SoundController.h"

MachineGun::MachineGun() 
	: Weapon("MachineGun", 20, 20, 20, 20, "MachineGunBullet", SDL_Rect{ 580, 431, 282, 186 })
{
	//this->bulletType = "MachineGunBullet";
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
		SoundController::GetInstance().PlaySound("assets/sounds/pistol.wav", 0);
	}
	else {
		SoundController::GetInstance().PlaySound("assets/sounds/gun-empty.wav", 0);
	}
}