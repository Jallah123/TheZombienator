#include "BulletMoveBehaviour.h"



BulletMoveBehaviour::BulletMoveBehaviour()
{
}


BulletMoveBehaviour::~BulletMoveBehaviour()
{
}

void BulletMoveBehaviour::Move(float dt)
{
	int speed = 5;
	// -- Get destination rect
	float newX = gameObject->getPosX();
	float newY = gameObject->getPosY();

	switch (gameObject->GetLookDir())
	{
	case NORTH:
		newY -= speed;
		break;
	case EAST:
		newX += speed;
		break;
	case SOUTH:
		newY += speed;
		break;
	case WEST:
		newX -= speed;
		break;
	}
	gameObject->SetPosition(newX, newY);
}
