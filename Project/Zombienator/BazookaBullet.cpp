#include "BazookaBullet.h"
#include "TextureFactory.h"


BazookaBullet::BazookaBullet()
{
	this->texture = TextureFactory::GenerateTextureFromImgUrl("assets/images/bullet.png");
	this->SetSize(20, 14);
}


BazookaBullet::~BazookaBullet()
{
}

void BazookaBullet::SetBehaviours()
{
	SetDrawBehaviour("MovingBulletDrawBehaviour");
	SetMoveBehaviour("BulletMoveBehaviour");
	SetCollideBehaviour("MovingBulletCollideBehaviour");
}
