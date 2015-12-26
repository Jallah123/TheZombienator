#include "BulletMoveBehaviour.h"
#include "Map.h"
#include "Bullet.h"

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

	Direction d = gameObject->GetMoveDir();
	if (d == NONE)
		d = gameObject->GetLookDir();

	switch (d)
	{
		case NORTHWEST:
			newX -= dtSpeed / modifer; 
			newY -= dtSpeed / modifer;
			break;
		case SOUTHWEST:
			newX -= dtSpeed / modifer; 
			newY += dtSpeed / modifer;
			break;
		case NORTHEAST:
			newX += dtSpeed / modifer; 
			newY -= dtSpeed / modifer;
			break;
		case SOUTHEAST:
			newX += dtSpeed / modifer; 
			newY += dtSpeed / modifer;
			break;
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
	SDL_Point p = { newX, newY };
	if (!SDL_PointInRect(&p, &this->map->GetBounds())) {
		Bullet* b = static_cast<Bullet*>(this->gameObject);
		b->Remove();
	}
	gameObject->SetPosition(newX, newY);
}
