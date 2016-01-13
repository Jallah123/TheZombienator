#pragma once
#include "Character.h"
#include "ZombieState.h"
#include <deque>
#include <string>
#include "Node.h"

class DrawContainer;
class AnimateContainer;
class MoveContainer;
class ActionContainer;
class CollideContainer;
class GameObjectContainer;

using std::string;

class Zombie :
	public Character
{
protected:
	const string basePath = "assets/images/spritesheets/";
	const string baseAttackPath = "assets/images/spritesheets/attack/";

	Character* target = nullptr;//Mike||Arnold
	ZombieState* currentState = nullptr;
	SDL_Texture* normalTexture = nullptr;
	SDL_Texture* AttackTexture = nullptr;
	SDL_Texture* DeadTexture = nullptr;

	float attackDamage = 0;
	float attackSpeed = 0;
	float soundSpeed = 0;

	const double sweetspotX = 35;
	const double sweetspotY = 25;

	deque<Node*> path;
public:
	Zombie();
	Zombie(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	virtual ~Zombie();
	virtual void Init();

	void SetTarget(Character* c) { this->target = c; }
	Character* GetTarget() { return this->target; }

	void Update(float dt) { if(currentState!= nullptr) currentState->Update(dt); }
	
	ZombieState* GetCurrentState() { return this->currentState; }
	void SetCurrentState(ZombieState* newState);
	bool IsInAttackRadius(Character* target);

	void SetNormalTexture(string path);
	void SetAttackTexture(string path);
	void SetDeadTexture(string path);
	void ChangeTexture(bool isAttack);

	void SetAttackDamage(float ad) { this->attackDamage = ad; }
	void SetAttackSpeed(float as) { this->attackSpeed = as; }
	void SetSoundSpeed(float ss) { this->soundSpeed = ss; }
	float GetAttackDamage() { return this->attackDamage; }
	float GetAttackSpeed() { return this->attackSpeed; }
	float GetSoundSpeed() { return this->soundSpeed; }

	deque<Node*>& GetPath() { return path; };
	deque<Node*> GetPathCopy() { return path; };
	void SetPath(deque<Node*> _path) { path = _path; };
	virtual void OnDeath() override;
};

