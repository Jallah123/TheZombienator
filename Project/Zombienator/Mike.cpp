#include "Mike.h"
#include "KeyboardInputHandler.h"



Mike::Mike() : Character(){}

void Mike::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, SDL_Renderer* ren)
{
	KeyboardInputHandler& kh = KeyboardInputHandler::GetInstance();
	this->SetContainers(drawC, animC, moveC, kh.inputContainer);
	SetDrawBehaviour("DrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetMoveBehaviour("MoveBehaviour");
	SetImage("assets/images/spritesheets/Boy1.png", *ren);
	SetSize(36, 38);
	SetFrames(3);
}


Mike::~Mike()
{
}
