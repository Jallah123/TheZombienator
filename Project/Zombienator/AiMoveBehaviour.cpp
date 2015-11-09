#include "MoveBehaviour.h"
#include "AiMoveBehaviour.h"
#include "Zombie.h"

AiMoveBehaviour::AiMoveBehaviour() : MoveBehaviour() {}


AiMoveBehaviour::~AiMoveBehaviour()
{
}

void AiMoveBehaviour::Move(float dt)
{
	if (!this->gameObject) return;

	Zombie* z = dynamic_cast<Zombie*>(this->gameObject);
	Character* target = z->GetTarget();
	if (target == nullptr) {
		// No target found, don't move
		z->SetMoveDir(Direction::NONE);
		return;//stop
	}

	float destX = target->getPosX();
	float destY = target->getPosY();

	// -- Get destination rect
	float newX = z->getPosX();
	float newY = z->getPosY();

	// -- Move directions
	bool up = destY + target->GetHeight() <= newY ;
	bool left = destX <= newX + z->GetWidth();
	bool down = destY >= newY + z->GetHeight();
	bool right = destX + target->GetWidth() >= newX;
	float speed = z->GetSpeed() * dt;

	if (up) {
		z->SetMoveDir(Direction::NORTH);//Reset to south look dir
		newY -= speed;
	}
	if (left) {
		z->SetMoveDir(Direction::WEST);//Reset to south look dir
		newX -= speed;
	}
	if (down) {
		z->SetMoveDir(Direction::SOUTH);//Reset to south look dir
		newY += speed;
	}
	if (right) {
		z->SetMoveDir(Direction::EAST);//Reset to south look dir
		newX += speed;
	}

	float finalX = newX;
	float finalY = newY;

	// -- Map Collision
	/*if (z->getMap()->checkCollision(newX, z->getPosY(), z->GetWidth(), z->GetHeight())) {
		finalX = z->getPosX();
	}
	if (z->getMap()->checkCollision(z->getPosX(), newY, z->GetWidth(), z->GetHeight())) {
		finalY = z->getPosY();
	}*/

	z->SetPosition(finalX, finalY);
}