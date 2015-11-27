#include "MachineGunBullet.h"
#include "TextureFactory.h"


MachineGunBullet::MachineGunBullet()
{
	SetDrawBehaviour("MovingBulletDrawBehaviour");
	SetMoveBehaviour("BulletMoveBehaviour");
	SetCollideBehaviour("NormalBulletCollideBehaviour");
	this->texture = TextureFactory::GenerateTextureFromImgUrl("assets/images/bullet.png");
	this->SetSize(20, 14);
}


MachineGunBullet::~MachineGunBullet()
{
}
