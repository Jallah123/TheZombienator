#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"
#pragma once

class GameObject;

class Character : public GameObject
{
protected:
	int damage;
	int health;
	int speed;

public:
	Character();
	~Character();

	void TakeHit(int damage);
	int GetHealth() const { return health; }
	int GetSpeed() const { return speed; }
	int GetDamage() const { return damage; }

	static GameObject* __stdcall Create() { return new Character(); }
};

#endif