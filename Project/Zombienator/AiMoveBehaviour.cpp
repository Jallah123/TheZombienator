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
		z->SetMoveDir(MoveDirection::NONE);
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
		z->SetMoveDir(MoveDirection::NORTH);//Reset to south look dir
		newY -= speed;
	}
	if (left) {
		z->SetMoveDir(MoveDirection::WEST);//Reset to south look dir
		newX -= speed;
	}
	if (down) {
		z->SetMoveDir(MoveDirection::SOUTH);//Reset to south look dir
		newY += speed;
	}
	if (right) {
		z->SetMoveDir(MoveDirection::EAST);//Reset to south look dir
		newX += speed;
	}

	// -- Screen bounds
	if (newX <= 0)
		newX = 0;
	if (newX >= 1245)
		newX = 1245;
	if (newY <= 0)
		newY = 0;
	if (newY >= 600)
		newY = 600;

	// -- Map Collision
	if (!z->getMap()->checkCollision(newX, newY, z->GetWidth(), z->GetHeight()))
		z->SetPosition(newX, newY);
	
}