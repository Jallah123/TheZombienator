#include "Mike.h"
#include "KeyboardInputHandler.h"



Mike::Mike() : Character(){}

void Mike::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, SDL_Renderer* ren)
{
	KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();
	this->SetContainers(drawC, animC, moveC, kh.inputContainer, actionC);

	SetDrawBehaviour("DrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("MoveBehaviour");
	SetActionBehaviour("ShootActionBehaviour");

	SetImage("assets/images/spritesheets/Boy1.png", *ren);
	SetSize(36, 38);
	SetFrames(3);
}


Mike::~Mike()
{
}
