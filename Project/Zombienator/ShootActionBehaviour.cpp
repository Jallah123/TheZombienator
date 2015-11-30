#include "ShootActionBehaviour.h"
#include "PlayableCharacter.h"
#include "InputContainer.h"

ShootActionBehaviour::ShootActionBehaviour()
{
	this->action = SDLK_SPACE;
}


ShootActionBehaviour::~ShootActionBehaviour()
{
}

void ShootActionBehaviour::Update(float dt)
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
