#include "PcMoveBehaviour.h"
#include "Character.h"
#include "InputContainer.h"


PcMoveBehaviour::PcMoveBehaviour() : MoveBehaviour() {}


PcMoveBehaviour::~PcMoveBehaviour()
{
}

void PcMoveBehaviour::Move(float dt)
{
	if (!this->gameObject) return;
	Character* c = dynamic_cast<Character*>(this->gameObject);
	InputContainer* iC = c->GetInputContainer();
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
	// Check X
	/*if (c->getMap()->checkCollision(newX, c->getPosY(), c->GetWidth(), c->GetHeight())) {
		finalX = c->getPosX();
	}
	// Check Y
	if (c->getMap()->checkCollision(c->getPosX(), newY, c->GetWidth(), c->GetHeight())) {
		finalY = c->getPosY();
	}*/
	c->SetPosition(finalX, finalY);
}
