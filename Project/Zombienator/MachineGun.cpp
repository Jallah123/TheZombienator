#include "MachineGun.h"
#include "GameObjectFactory.h"
#include "MachineGunBullet.h"
#include "SoundController.h"

MachineGun::MachineGun() : Weapon("assets/images/MachineGun.png")
{
	this->name = "MachineGun";
	this->delay = 20;
	this->damage = 20;  // 1/5 of a zombie's health
	this->rounds = 20;
	this->bulletType = "MachineGunBullet";
	GameObjectFactory::Instance()->Register(bulletType, [](void) -> GameObject* { return new MachineGunBullet(); });
}


MachineGun::~MachineGun()
{
}

void MachineGun::Fire()
{
	if (rounds != 0) {
		MachineGunBullet* b = GameObjectFactory::Instance()->CreateMachineGunBullet(this->character);
		SoundController::GetInstance().PlaySound("assets/sounds/pistol.wav", 0);
	}
	else {
		SoundController::GetInstance().PlaySound("assets/sounds/gun-empty.wav", 0);
	}
}