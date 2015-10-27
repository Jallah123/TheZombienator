#include "ShootActionBehaviour.h"
#include <iostream>
#include "Character.h"
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
	Character* c = dynamic_cast<Character*>(this->gameObject);
	InputContainer* iC = c->GetInputContainer();
	if (iC == nullptr) return;
	//Draw Line

	bool canShoot = iC->GetKeyState(this->action);
	std::cout << "SHOOT ? " << canShoot << std::endl;
}
