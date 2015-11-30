#pragma once
#include "SoundController.h"
class Zombie;

class ZombieState
{
public:
	ZombieState();
	~ZombieState();
	void SetOwner(Zombie* _owner) { owner = _owner; };
	Zombie* GetOwner() { return owner; };
	virtual void CheckState() = 0;
	virtual void Update(float dt) = 0;
private:
	Zombie* owner = nullptr;
};