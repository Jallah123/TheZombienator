#include "NormalBullet.h"
#include "BehaviourFactory.h"


NormalBullet::NormalBullet()
{
	SetDrawBehaviour("NormalBulletDrawBehaviour");
	SetCollideBehaviour("NormalBulletCollideBehaviour");
}


NormalBullet::~NormalBullet()
{
}

