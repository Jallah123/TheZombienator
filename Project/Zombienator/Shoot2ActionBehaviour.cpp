#include "Shoot2ActionBehaviour.h"
#include "PlayableCharacter.h"
#include "InputContainer.h"

Shoot2ActionBehaviour::Shoot2ActionBehaviour()
{
	this->action = SDLK_RCTRL;
}


Shoot2ActionBehaviour::~Shoot2ActionBehaviour()
{
}

void Shoot2ActionBehaviour::Update(float dt)
{
	if (!this->gameObject) return;
	PlayableCharacter* c = static_cast<PlayableCharacter*>(this->gameObject);
	InputContainer* iC = c->GetInputContainer();
	if (iC == nullptr) return;

	//Performace check
	if (elapsedTime < maxElapsed) elapsedTime += dt;

	bool keyPressed = iC->GetKeyState(this->action);
	Weapon* w = c->GetWeapon();
	if (keyPressed && elapsedTime > w->GetDelay()) {
		w->Fire();//BLAST THOSE ZOMBIES
		elapsedTime = 0;//Reset 
	}
}
