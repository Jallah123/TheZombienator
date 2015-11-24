#pragma once
#include <string>
#include <SDL_image.h>
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
	SDL_Texture* hudTexture;
	PlayableCharacter* character = nullptr;
public:
	Weapon();
	Weapon(std::string imagePath);
	virtual ~Weapon();

	virtual void Fire() = 0;

	int GetDelay() { return this->delay; }
	int GetRounds() { return this->rounds; }
	int GetDamage() { return this->damage; }
	SDL_Texture* GetHudTexture() { return hudTexture;  }

	void GiveTo(PlayableCharacter* c) { this->character = c; }
};

