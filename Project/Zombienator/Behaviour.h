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
};