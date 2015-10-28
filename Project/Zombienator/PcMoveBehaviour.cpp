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
	bool up = iC->GetKeyState('w');
	bool left = iC->GetKeyState('a');
	bool down = iC->GetKeyState('s');
	bool right = iC->GetKeyState('d');
	float speed = c->GetSpeed() * dt;

	c->SetMoveDir(MoveDirection::NONE);//Don't move if no button is pressed

	// -- Move directions
	if (up) {
		c->SetMoveDir(MoveDirection::NORTH);//Reset to south look dir
		newY -= speed;
	}
	if (left) {
		c->SetMoveDir(MoveDirection::WEST);//Reset to south look dir
		newX -= speed;
	}
	if (down) {
		c->SetMoveDir(MoveDirection::SOUTH);//Reset to south look dir
		newY += speed;
	}
	if (right) {
		c->SetMoveDir(MoveDirection::EAST);//Reset to south look dir
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
	if(!c->getMap()->checkCollision(newX, newY, c->GetWidth(), c->GetHeight()))
		c->SetPosition(newX, newY);		// -- Set destination rect
}
