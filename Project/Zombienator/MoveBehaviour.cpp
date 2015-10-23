#include "MoveBehaviour.h"
#include "Character.h"

MoveBehaviour::MoveBehaviour() : Behaviour() {}
MoveBehaviour::~MoveBehaviour() {}

void MoveBehaviour::Move(float dt, int ticks, KeyboardInputHandler& iC) {
	
	if (!this->gameObject) return;
	Character* c = dynamic_cast<Character*>(this->gameObject);
	
	int frames = c->GetFrames();
	if (frames == 0) return;

	// -- Get destination rect
	float newX = c->getPosX();
	float newY = c->getPosY();

	// -- Move directions
	bool up = iC.inputContainer->GetKeyState('w');
	bool left = iC.inputContainer->GetKeyState('a');
	bool down = iC.inputContainer->GetKeyState('s');
	bool right = iC.inputContainer->GetKeyState('d');

	c->SetMoveDir(MoveDirection::NONE);//Don't move if no button is pressed

	// -- Get input from user
	if (up) {
		c->SetMoveDir(MoveDirection::NORTH);//Reset to south look dir
		newY -= c->GetSpeed() * dt;
	}
	if (left) {
		c->SetMoveDir(MoveDirection::WEST);//Reset to south look dir
		newX -= c->GetSpeed() * dt;
	}
	if (down) {
		c->SetMoveDir(MoveDirection::SOUTH);//Reset to south look dir
		newY += c->GetSpeed() * dt;
	}
	if (right) {
		c->SetMoveDir(MoveDirection::EAST);//Reset to south look dir
		newX += c->GetSpeed() * dt;
	}

	// -- Set destination rect
	c->SetPosition(newX, newY);
}
