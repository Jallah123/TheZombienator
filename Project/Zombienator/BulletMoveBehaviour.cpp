#include "BulletMoveBehaviour.h"



BulletMoveBehaviour::BulletMoveBehaviour()
{
}


BulletMoveBehaviour::~BulletMoveBehaviour()
{
}

void BulletMoveBehaviour::Move(float dt)
{
	int dtSpeed = speed * dt;
	// -- Get destination rect
	float newX = gameObject->getPosX();
	float newY = gameObject->getPosY();

	switch (gameObject->GetLookDir())
	{
	case NORTH:
		newY -= dtSpeed;
		break;
	case EAST:
		newX += dtSpeed;
		break;
	case SOUTH:
		newY += dtSpeed;
		break;
	case WEST:
		newX -= dtSpeed;
		break;
	}
	gameObject->SetPosition(newX, newY);
}
