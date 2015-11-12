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

	z->SetMoveDir(Direction::NONE);

	// -- Move directions

	if (up) {
		z->SetMoveDir(Direction::NORTH);
		z->SetLookDir(Direction::NORTH);
		newY -= speed;
	}
	if (left) {
		z->SetMoveDir(Direction::WEST);
		z->SetLookDir(Direction::WEST);
		newX -= speed;
	}
	if (down) {
		z->SetMoveDir(Direction::SOUTH);
		z->SetLookDir(Direction::SOUTH);
		newY += speed;
	}
	if (right) {
		z->SetMoveDir(Direction::EAST);
		z->SetLookDir(Direction::EAST);
		newX += speed;
	}

	float finalX = newX;
	float finalY = newY;

	// -- Map Collision
	if (collisionLayer->HasCollision(SDL_Rect{ static_cast<int>(newX+.5f), static_cast<int>(z->getPosY()+.5f), z->GetWidth(), z->GetHeight() })) {
		finalX = z->getPosX();
	}
	if (collisionLayer->HasCollision(SDL_Rect{ static_cast<int>(z->getPosX()+.5f), static_cast<int>(newY + .5f), z->GetWidth(), z->GetHeight() })) {
		finalY = z->getPosY();
	}

	z->SetPosition(finalX, finalY);
}