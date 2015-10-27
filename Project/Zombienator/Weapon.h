#pragma once
#include <string>
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "CollideContainer.h"

using std::string;
class PlayableCharacter;

class Weapon
{
protected:
	string name = "";
	int rounds = 0;
	int damage = 0;
	int delay = 0;//Milliseconds
	string bulletType = "";
	PlayableCharacter* character = nullptr;
public:
	Weapon();
	virtual ~Weapon();

	virtual void Fire() = 0;

	int GetDelay() { return this->delay; }
	int GetRounds() { return this->rounds; }
	int GetDamage() { return this->damage; }

	void GiveTo(PlayableCharacter* c) { this->character = c; }
};

