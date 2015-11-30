#include "MachineGun.h"
#include "GameObjectFactory.h"
#include "MachineGunBullet.h"
#include "SoundController.h"

MachineGun::MachineGun() : Weapon("assets/images/Pistol.png")
{
	this->delay = 20;
	this->damage = 20;  // 1/5 of a zombie's health
	this->bulletType = "MachineGunBullet";
	GameObjectFactory::Instance()->Register(bulletType, [](void) -> GameObject* { return new MachineGunBullet(); });
}


MachineGun::~MachineGun()
{
}

void MachineGun::Fire()
{
	MachineGunBullet* b = GameObjectFactory::Instance()->CreateMachineGunBullet(this->character);
	SoundController::GetInstance().PlaySound("assets/sounds/pistol.wav", 0);
}
