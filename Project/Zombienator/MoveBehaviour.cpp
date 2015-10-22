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

	// -- Get input from user
	if (up) {
		newY -= c->GetSpeed() * dt;
	}
	if (left) {
		newX -= c->GetSpeed() * dt;
	}
	if (down) {
		newY += c->GetSpeed() * dt;
	}
	if (right) {
		newX += c->GetSpeed() * dt;
	}

	// -- Set destination rect
	c->SetPosition(newX, newY);
}
