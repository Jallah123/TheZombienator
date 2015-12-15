#pragma once
#include "Character.h"
#include "ZombieState.h"
#include <queue>

class DrawContainer;
class AnimateContainer;
class MoveContainer;
class ActionContainer;
class CollideContainer;
class GameObjectContainer;

class Zombie :
	public Character
{
public:
	Zombie();
	~Zombie();
	void Init(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC, SDL_Renderer* ren);

	void SetTarget(Character* c) { this->target = c; }
	Character* GetTarget() { return this->target; }

	void Update(float dt) { currentState->Update(dt); }
	
	ZombieState* GetCurrentState() { return this->currentState; }
	void SetCurrentState(ZombieState* newState);
	bool IsInAttackRadius(Character* target);

	void SetNormalTexture(string path);
	void SetAttackTexture(string path);
	void ChangeTexture(bool isAttack);

	void SetAttackDamage(float ad) { this->attackDamage = ad; }
	void SetAttackSpeed(float as) { this->attackSpeed = as; }
	void SetSoundSpeed(float ss) { this->soundSpeed = ss; }
	float GetAttackDamage() { return this->attackDamage; }
	float GetAttackSpeed() { return this->attackSpeed; }
	float GetSoundSpeed() { return this->soundSpeed; }

	queue<int> GetPath() { return path; };
	void SetPath(queue<int> _path) { path = _path; };
	int currentPathIndex = 0;
private:
	Character* target = nullptr;//Mike||Arnold
	ZombieState* currentState = nullptr;
	SDL_Texture* normalTexture = nullptr;
	SDL_Texture* AttackTexture = nullptr;
	
	float attackDamage = 0;
	float attackSpeed = 0;
	float soundSpeed = 0;

	const double sweetspotX = 35;
	const double sweetspotY = 25;

	queue<int> path;
};

