#pragma once
#include "GameObject.h"
#include "HudVisitor.h"
#include <vector>
//Containers
class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;
class ActionContainer;
class CollideContainer;
class GameObjectContainer;

//Behaviours
class DrawBehaviour;
class AnimateBehaviour;
class MoveBehaviour;
class ActionBehaviour;
class CollideBehaviour;

class Character : 
	public GameObject
{
protected:
	int damage = 0;
	int health;
	int maxHealth;
	float speed = 0;
	int animationFrames = 0;

	//Containers
	AnimateContainer* animateContainer = nullptr;
	DrawContainer* drawContainer = nullptr;
	MoveContainer* moveContainer = nullptr;
	InputContainer* inputContainer = nullptr;
	ActionContainer* actionContainer = nullptr;
	CollideContainer* collideContainer = nullptr;
	GameObjectContainer* gameObjectContainer = nullptr;

	//Behaviours
	DrawBehaviour* drawBehaviour = nullptr;
	AnimateBehaviour* animateBehaviour = nullptr;
	MoveBehaviour* moveBehaviour = nullptr;
	CollideBehaviour* collideBehaviour = nullptr;
	//Character can have multiple actions
	std::vector<ActionBehaviour*> actionBehaviours = {};

public:
	Character();
	virtual ~Character();

	virtual void TakeHit(int damage);
	int GetHealth() const { return health; }
	int GetMaxHealth() const { return maxHealth; }
	float GetSpeed() const { return speed; }
	int GetDamage() const { return damage; }
	int GetFrames() const { return animationFrames; }

	void SetSpeed(float s) { speed = s; }
	void SetFrames(int f) { animationFrames = f; }
	void SetHealth(int h) { this->health = h; if (health > maxHealth) health = maxHealth; }
	void SetMaxHealth(int h) { this->maxHealth = h; }
	bool IsDeath() { if (!this->health) return true; return false; }

	void SetContainers(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, InputContainer* inputC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC);
	void SetDrawBehaviour(std::string name);
	void SetAnimateBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);
	void SetActionBehaviour(std::string name);
	void SetCollideBehaviour(std::string name);

	void Accept(HudVisitor& visitor) { visitor.Visit(this); };

	InputContainer* GetInputContainer() { return inputContainer; }
	GameObjectContainer* GetGameObjectContainer() { return this->gameObjectContainer; }

	void Remove();
};