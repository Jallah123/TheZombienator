#include "ZombieWalkingState.h"
#include "ZombieStateFactory.h"


ZombieWalkingState::ZombieWalkingState()
{
}


ZombieWalkingState::~ZombieWalkingState()
{
}


void ZombieWalkingState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	if (target == nullptr && !target->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, z));
		return;
	}
	else if (z->IsInAttackRadius(target)) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::ATTACKING, z));
		return;
	}
}

void ZombieWalkingState::Update(float dt)
{
	CheckState();

	Zombie* z = GetOwner();
	Character* target = z->GetTarget();

	float destX = target->getPosX();
	float destY = target->getPosY();

	// -- Get destination rect
	SDL_Rect cRect = z->GetCollideRect();
	float newX = z->getPosX();
	float newY = z->getPosY();

	// -- Move directions
	bool up = destY + target->GetHeight() <= newY;
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
	if (z->GetCollisionLayer()->HasCollision(SDL_Rect{ static_cast<int>(newX + .5f), static_cast<int>(z->getPosY() + .5f), z->GetWidth(), z->GetHeight() })) {
		finalX = z->getPosX();
	}
	if (z->GetCollisionLayer()->HasCollision(SDL_Rect{ static_cast<int>(z->getPosX() + .5f), static_cast<int>(newY + .5f), z->GetWidth(), z->GetHeight() })) {
		finalY = z->getPosY();
	}

	z->SetPosition(finalX, finalY);
}