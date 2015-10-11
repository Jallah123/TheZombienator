#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H
#include "Character.h"
#pragma once

class Character;

class Behaviour
{
protected:
	Character* character;
public:
	Behaviour();
	~Behaviour();

	void SetCharacter(Character* c) { character = c; }

	virtual void Animate(float dt) = 0;
	virtual void Update(float dt) = 0;
	virtual void FeelForce(float dt) = 0;
	virtual void Move(float dt) = 0;
	virtual void Collide(float dt) = 0;
	virtual void Input(float dt) = 0;
	virtual void Draw(float dt, SDL_Renderer& ren) = 0;
};

#endif
