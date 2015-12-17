#include "MachineGunBullet.h"
#include "TextureFactory.h"


MachineGunBullet::MachineGunBullet()
{
	
	this->texture = TextureFactory::GenerateTextureFromImgUrl("assets/images/bullet.png");
	this->SetSize(10, 7);
}


MachineGunBullet::~MachineGunBullet()
{
}

void MachineGunBullet::SetBehaviours()
{
	SetDrawBehaviour("MovingBulletDrawBehaviour");
	SetMoveBehaviour("BulletMoveBehaviour");
	SetCollideBehaviour("MovingBulletCollideBehaviour");
}
