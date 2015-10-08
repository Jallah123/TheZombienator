#include "Character.h"
#pragma once
class Behaviour
{
protected:
	Character character;
public:
	Behaviour();
	~Behaviour();

	void SetCharacter(Character c) { character = c; }

	virtual void Animate() = 0;
	virtual void Update() = 0;
	virtual void FeelForce() = 0;
	virtual void Move() = 0;
	virtual void Collide() = 0;
	virtual void Input() = 0;
	virtual void Draw() = 0;
};

