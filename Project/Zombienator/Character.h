#pragma once
#include "GameObject.h"
#pragma once
class Character : public GameObject
{
protected:
	int damage;
	int health;
	int speed;

public:
	Character();
	~Character();

	void TakeHit();
	int GetHealth() const { return health; }
	int GetSpeed() const { return speed; }
	int GetDamage() const { return damage; }

};

