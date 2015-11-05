#pragma once
#include "Behaviour.h"
class Character;
class CharacterContainer;

class CollideBehaviour :
	public Behaviour
{
protected:
	CharacterContainer* characterContainer;
public:
	CollideBehaviour();
	void SetCharacterContainer(CharacterContainer* c) { this->characterContainer = c; }
	virtual ~CollideBehaviour();
	virtual bool Collide(float dt) = 0;
};

