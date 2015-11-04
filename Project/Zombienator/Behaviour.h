#pragma once
#include <memory>
#include "GameObject.h"

class Behaviour
{
private:
	bool canRemove = false;
protected:
	GameObject* gameObject;
public:
	Behaviour();
	virtual ~Behaviour();
	GameObject* GetGameObject() { return gameObject; }
	void SetGameObject(GameObject* go) { gameObject = go; }
	bool CanBeRemove() { return this->canRemove; }
	void CanRemove(bool c) { this->canRemove = c; }
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