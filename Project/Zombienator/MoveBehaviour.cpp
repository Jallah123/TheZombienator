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
	SDL_Rect destR = c->GetDestinationRect();

	// -- Move directions
	bool up = iC.inputContainer->GetKeyState('w');
	bool left = iC.inputContainer->GetKeyState('a');
	bool down = iC.inputContainer->GetKeyState('s');
	bool right = iC.inputContainer->GetKeyState('d');

	// -- Get input from user
	if (up) {
		destR.y = (destR.y - c->GetSpeed()) * dt;
	}
	if (left) {
		destR.x = (destR.x - c->GetSpeed()) * dt;
	}
	if (down) {
		destR.y = (destR.y + c->GetSpeed()) * dt;
	}
	if (right) {
		destR.x = (destR.x + c->GetSpeed()) * dt;
	}

	// -- Set destination rect
	c->SetDestinationRect(destR);
}
