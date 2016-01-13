#pragma once
#include "ZombieState.h"
#include <vector>

class Zombie;
class Character;
class GameObject;

class BadassWalkingState :
	public ZombieState
{
public:
	BadassWalkingState();
	~BadassWalkingState();

	bool LineInterSects(Zombie & owner, Character & target, std::vector<GameObject*> gos);

	virtual void CheckState() override;
	virtual void Update(float dt) override;
};

