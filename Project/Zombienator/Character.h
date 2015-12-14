#pragma once
#include "GameObject.h"

class DrawContainer;
class AnimateContainer;
class MoveContainer;
class ActionContainer;
class CollideContainer;
class GameObjectContainer;

class Character : 
	public GameObject
{
protected:
	int damage = 0;
	int health = 100;
	int maxHealth = 100;
	float speed = 0;
	
public:
	Character();
	Character(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	virtual ~Character();

	virtual void TakeHit(int damage);
	int GetHealth() const { return health; }
	int GetMaxHealth() const { return maxHealth; }
	float GetSpeed() const { return speed; }
	int GetDamage() const { return damage; }

	void SetSpeed(float s) { speed = s; }
	
	void SetHealth(int h) { this->health = h; if (health > maxHealth) health = maxHealth; }
	void SetMaxHealth(int h) { this->maxHealth = h; }
	bool IsDeath() { return health <= 0 ? true : false; }
	virtual void OnDeath();
};