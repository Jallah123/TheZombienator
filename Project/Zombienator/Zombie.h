#pragma once
#include "Character.h"
#include "ZombieState.h"

class DrawContainer;
class AnimateContainer;
class MoveContainer;
class ActionContainer;
class CollideContainer;
class CharacterContainer;

class Zombie :
	public Character
{
public:
	Zombie();
	~Zombie();
	void Init(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, ActionContainer* actionC, CollideContainer* collideC, CharacterContainer* characterC, SDL_Renderer* ren);

	void SetTarget(Character* c) { this->target = c; }
	Character* GetTarget() { return this->target; }

	void Update(float dt) { currentState->Update(dt); }
	
	void SetCurrentState(ZombieState* newState) { currentState = newState; };
	bool IsInAttackRadius(Character* target);
private:
	Character* target = nullptr;//Mike||Arnold
	ZombieState* currentState = nullptr;
};

