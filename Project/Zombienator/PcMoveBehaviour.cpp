#include "PcMoveBehaviour.h"
#include "Character.h"
#include "InputContainer.h"
#include "GameObjectContainer.h"

PcMoveBehaviour::PcMoveBehaviour() : MoveBehaviour() {}


PcMoveBehaviour::~PcMoveBehaviour()
{
}

void PcMoveBehaviour::Move(float dt)
{
	if (!this->gameObject) return;
	Character* c = dynamic_cast<Character*>(this->gameObject);
	InputContainer* iC = c->GetInputContainer();
	GameObjectContainer* goc = c->GetGameObjectContainer();
	if (iC == nullptr) return;
	int frames = c->GetFrames();
	if (frames == 0) return;

	// -- Get destination rect
	float newX = c->getPosX();
	float newY = c->getPosY();
	
	// -- Get input from user
	bool up = iC->GetKeyState(SDLK_w);
	bool left = iC->GetKeyState(SDLK_a);
	bool down = iC->GetKeyState(SDLK_s);
	bool right = iC->GetKeyState(SDLK_d);
	float speed = c->GetSpeed() * dt;

	c->SetMoveDir(Direction::NONE);

	// -- Move directions
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

	float finalX = newX;
	float finalY = newY;

	// -- Map Collision
	std::vector<GameObject*> gameObjects = goc->GetGameObjects();
	for (auto& g : gameObjects)
	{
		if (g != this->gameObject) {
			SDL_Rect* r = this->gameObject->GetDestinationRect();
			r->x = static_cast<int>(newX + .5f);
			r->y = static_cast<int>(c->getPosY() + .5f);
			if (SDL_HasIntersection(r, g->GetDestinationRect()))
				finalX = c->getPosX();

			r->x = static_cast<int>(c->getPosX() + .5f);
			r->y = static_cast<int>(newY + .5f);
			if (SDL_HasIntersection(r, g->GetDestinationRect()))
				finalY = c->getPosY();
		}
	}
	//Player must stay within level bounds
	if(finalX < 0 || finalX > goc->GetBounds().w - c->GetWidth())
		finalX = c->getPosX();
	if (finalY < 0 || finalY > goc->GetBounds().h - c->GetHeight())
		finalY = c->getPosY();

	c->CanMove(true);
	c->SetPosition(finalX, finalY);
}
