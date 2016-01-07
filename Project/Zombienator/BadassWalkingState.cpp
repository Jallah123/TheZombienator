#pragma once
#include "BadassWalkingState.h"
#include "ZombieStateFactory.h"
#include "GameObjectContainer.h"
#include "GameMath.h"
#include "Zombie.h"
#include <SDL_rect.h>

BadassWalkingState::BadassWalkingState()
{
}


BadassWalkingState::~BadassWalkingState()
{
}

bool BadassWalkingState::LineInterSects(Zombie& owner, Character& target, std::vector<GameObject*> gos)
{
	for (auto& g : gos)
	{
		SDL_Point b{ owner.getPosX(), owner.getPosY() };
		SDL_Point e{ target.getPosX(), target.getPosY() };
		if (SDL_IntersectRectAndLine(g->GetDestinationRect(), &b.x, &b.y, &e.x, &e.y))
		{
			return true;
		}
	}
	return false;
}

void BadassWalkingState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();

	if (z->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::DEAD, z));
		return;
	}
	else if (LineInterSects(*z, *target, z->GetGameObjectContainer()->GetCollideableObjects())==false) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::BAD_ATTACK, z));
		return;
	}
	else if (target == nullptr && !target->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::BAD_STILL, z));
		return;
	}
}

void BadassWalkingState::Update(float dt)
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	GameObjectContainer* goc = z->GetGameObjectContainer();

	float destX = target->getPosX();
	float destY = target->getPosY();

	// -- Get destination rect
	SDL_Rect* goRect = z->GetCollideRect();
	float newX = z->getPosX();
	float newY = z->getPosY();

	// -- Move directions
	bool left = destX + target->GetWidth() <= newX;
	bool right = destX >= newX + z->GetWidth();
	bool up = destY + (target->GetHeight() / 2) <= newY;
	bool down = destY >= newY + (z->GetHeight() / 2);

	float speed = z->GetSpeed() * dt;

	z->SetMoveDir(Direction::NONE);

	// -- Move directions
	if (left) {
		z->SetMoveDir(Direction::WEST);
		z->SetLookDir(Direction::WEST);
		newX -= speed;
	}
	if (right) {
		z->SetMoveDir(Direction::EAST);
		z->SetLookDir(Direction::EAST);
		newX += speed;
	}
	if (up) {
		z->SetMoveDir(Direction::NORTH);
		z->SetLookDir(Direction::NORTH);
		newY -= speed;
	}
	if (down) {
		z->SetMoveDir(Direction::SOUTH);
		z->SetLookDir(Direction::SOUTH);
		newY += speed;
	}


	float finalX = newX;
	float finalY = newY;

	// -- Map Collision
	std::vector<GameObject*> gameObjects = goc->GetCollideableObjects();
	for (auto& g : gameObjects)
	{
		if (g != z) {
			goRect->x = static_cast<int>(newX + .5f);
			goRect->y = static_cast<int>(z->getPosY() + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalX = z->getPosX();

			goRect->x = static_cast<int>(z->getPosX() + .5f);
			goRect->y = static_cast<int>(newY + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalY = z->getPosY();
		}
	}

	z->SetPosition(finalX, finalY);
	CheckState();
}
