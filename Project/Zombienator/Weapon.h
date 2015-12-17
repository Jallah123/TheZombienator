#pragma once
#include <string>
#include <SDL_image.h>
#include "HudVisitor.h"

using std::string;
class PlayableCharacter;
class Weapon
{
protected:
	string name = "";
	int rounds = 0;
	int maxRounds = 0;
	int damage = 0;
	int delay = 0;//Milliseconds
	string bulletType = "";
	SDL_Rect hudSourceRect = { 0,0,0,0 };
	PlayableCharacter* character = nullptr;
public:
	Weapon();
	Weapon(std::string name, int rounds, int maxRounds, int delay, int damage, std::string bulletType, SDL_Rect srcRect);
	virtual ~Weapon();

	virtual void Fire();
	int GetDelay() { return this->delay; }
	int GetRounds() { return this->rounds; }
	int GetDamage() { return this->damage; }
	string GetName() { return name; };
	SDL_Rect GetHudSourceRect() { return hudSourceRect; }

	void GiveTo(PlayableCharacter* c) { this->character = c; }
};

