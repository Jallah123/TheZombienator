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
	int maxRounds = 100;
	int damage = 0;
	int delay = 0;//Milliseconds
	string bulletType = "";
	SDL_Texture* hudTexture = nullptr;
	PlayableCharacter* character = nullptr;
public:
	Weapon();
	Weapon(std::string imagePath);
	virtual ~Weapon();

	virtual void Fire();
	void Accept(HudVisitor* visitor) { visitor->Visit(this); };
	
	string GetName() { return name; };
	int GetDelay() { return this->delay; }
	int const GetRounds() { return this->rounds; }
	int const GetMaxRounds() { return this->maxRounds; }
	int const GetDamage() { return this->damage; }
	
	void SetMaxAmmo() { rounds = maxRounds; }
	bool HasMaxAmmo() { return rounds == maxRounds; }
	
	SDL_Texture* GetHudTexture() { return hudTexture;  }

	void GiveTo(PlayableCharacter* c) { this->character = c; }
};

