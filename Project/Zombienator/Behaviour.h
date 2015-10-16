#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#pragma once
#include <memory>
#include "GameObject.h"

class Behaviour
{
protected:
	GameObject* gameObject;
public:
	Behaviour();
	virtual ~Behaviour();

	void SetGameObject(GameObject* go) { gameObject = go; }
/*
	virtual void Animate(float dt) = 0;
	virtual void Update(float dt) = 0;
	virtual void FeelForce(float dt) = 0;
	virtual void Move(float dt) = 0;
	virtual void Collide(float dt) = 0;
	virtual void Input(float dt) = 0;
	virtual void Draw(float dt, SDL_Renderer& ren) = 0;
	*/
};
#endif