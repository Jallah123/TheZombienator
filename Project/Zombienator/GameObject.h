#include "MoveDirection.cpp"

#include "DrawContainer.h"
#include "InputContainer.h"
#include "CollideContainer.h"
#include "MoveContainer.h"
#include "ForceContainer.h"
#include "AnimateContainer.h"

#pragma once

class GameObject
{
private:
	MoveDirection moveDirection;
	
	//Containers
	/*DrawContainer drawContainer;
	InputContainer inputContainer;
	CollideContainer collideContainer;*/
	//Behaviours

public:
	GameObject();
	~GameObject();
};

