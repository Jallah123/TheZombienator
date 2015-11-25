#include "MoveBehaviour.h"
#include "AiMoveBehaviour.h"
#include "Zombie.h"
#include "GameObjectContainer.h"
AiMoveBehaviour::AiMoveBehaviour() : MoveBehaviour() {}


AiMoveBehaviour::~AiMoveBehaviour()
{
}

void AiMoveBehaviour::Move(float dt)
{
	if (!this->gameObject) return;

	Zombie* z = dynamic_cast<Zombie*>(this->gameObject);
	Character* target = z->GetTarget();
	GameObjectContainer* goc = z->GetGameObjectContainer();
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
	std::vector<GameObject*> gameObjects = goc->GetGameObjects();
	for (auto& g : gameObjects)
	{
		if (g != this->gameObject) {
			SDL_Rect* r = this->gameObject->GetDestinationRect();
			r->x = static_cast<int>(newX + .5f);
			r->y = static_cast<int>(z->getPosY() + .5f);
			if (SDL_HasIntersection(r, g->GetDestinationRect()))
				finalX = z->getPosX();

			r->x = static_cast<int>(z->getPosX() + .5f);
			r->y = static_cast<int>(newY + .5f);
			if (SDL_HasIntersection(r, g->GetDestinationRect()))
				finalY = z->getPosY();
		}
	}
	z->SetPosition(finalX, finalY);
}