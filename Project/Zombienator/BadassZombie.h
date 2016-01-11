#pragma once
#include "Zombie.h"

class DrawContainer;
class AnimateContainer;
class MoveContainer;
class ActionContainer;
class CollideContainer;
class GameObjectContainer;

class BadassZombie :
	public Zombie
{
public:
	BadassZombie();
	BadassZombie(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);

	~BadassZombie();

	virtual void Init() override;
	virtual void OnDeath() override;
};

