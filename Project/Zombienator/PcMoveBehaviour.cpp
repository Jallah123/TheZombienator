#include "PcMoveBehaviour.h"
#include "Bullet.h"
#include "InputContainer.h"
#include "GameObjectContainer.h"
#include "KeyBinding.h"
#include "PlayableCharacter.h"

PcMoveBehaviour::PcMoveBehaviour() : MoveBehaviour() {}


PcMoveBehaviour::~PcMoveBehaviour()
{
}

void PcMoveBehaviour::Move(float dt)
{
	if (!this->gameObject) return;
	if (!this->gameObject->CanMove()) return;

	PlayableCharacter* c = dynamic_cast<PlayableCharacter*>(this->gameObject);
	InputContainer* iC = c->GetInputContainer();
	GameObjectContainer* goc = c->GetGameObjectContainer();
	SDL_Rect* goRect = c->GetCollideRect();

	if (iC == nullptr) return;

	// -- Get destination rect
	float newX = c->getPosX();
	float newY = c->getPosY();
	
	// -- Get input from user
	bool up = iC->GetKeyState(c->getKeyBinding()->UP);
	bool left = iC->GetKeyState(c->getKeyBinding()->LEFT);
	bool down = iC->GetKeyState(c->getKeyBinding()->DOWN);
	bool right = iC->GetKeyState(c->getKeyBinding()->RIGHT);
	float speed = c->GetSpeed() * dt;

	c->SetMoveDir(Direction::NONE);

	if (up) {
		c->SetMoveDir(Direction::NORTH);
		c->SetLookDir(Direction::NORTH);
		newY -= speed;
	}
	if (left) {
		c->SetMoveDir(Direction::WEST);
		c->SetLookDir(Direction::WEST);
		newX -= speed;
	}
	if (down) {
		c->SetMoveDir(Direction::SOUTH);
		c->SetLookDir(Direction::SOUTH);
		newY += speed;
	}
	if (right) {
		c->SetMoveDir(Direction::EAST);
		c->SetLookDir(Direction::EAST);
		newX += speed;
	}

	if (up && left)
		c->SetMoveDir(Direction::NORTHWEST);
	if (up && right)
		c->SetMoveDir(Direction::NORTHEAST);
	if (left && down)
		c->SetMoveDir(Direction::SOUTHWEST);
	if (right && down)
		c->SetMoveDir(Direction::SOUTHEAST);

	float finalX = newX;
	float finalY = newY;

	// -- Map Collision
	std::vector<GameObject*> gameObjects = goc->GetCollideableObjects();
	for (auto& g : gameObjects)
	{
		if (dynamic_cast<Bullet*>(g)) continue;

		if (g != this->gameObject) {
			goRect->x = static_cast<int>(newX + .5f);
			goRect->y = static_cast<int>(c->getPosY() + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalX = c->getPosX();

			goRect->x = static_cast<int>(c->getPosX() + .5f);
			goRect->y = static_cast<int>(newY + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalY = c->getPosY();
		}
	}

	//Player must stay within level bounds
	if(finalX < 0 || finalX > goc->GetBounds().w - c->GetWidth())
		finalX = c->getPosX();
	if (finalY < 0 || finalY > goc->GetBounds().h - c->GetHeight())
		finalY = c->getPosY();

	c->SetPosition(finalX, finalY);

}
