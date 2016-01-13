#include "ZombieBlubberBullet.h"
#include "TextureFactory.h"


ZombieBlubberBullet::ZombieBlubberBullet()
{
	this->texture = TextureFactory::CreateTexture("assets/images/spritesheets/slime.png");
	this->SetSize(32, 32);
}


ZombieBlubberBullet::~ZombieBlubberBullet()
{
}

void ZombieBlubberBullet::SetBehaviours()
{
	SetDrawBehaviour("MovingBulletDrawBehaviour");
	SetMoveBehaviour("BulletMoveBehaviour");
	SetCollideBehaviour("ZombieBlubberCollideBehaviour");
}
