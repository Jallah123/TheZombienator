#pragma once
#include "Character.h"
#include "Weapon.h"
#include <vector>

class PlayableCharacter
	: public Character
{
protected:
	std::vector<Weapon*> weapons = {};
	Weapon* weapon = nullptr;
	bool isFlare = false;

public:
	PlayableCharacter();
	PlayableCharacter(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	virtual ~PlayableCharacter();

	void AddWeapon(Weapon* w);
	Weapon* GetWeapon() { return this->weapon; }
	void SetWeapon(Weapon* w);
	void NextWeapon();
	void PreviousWeapon();
	void Teleport(SDL_Renderer* ren);
	void SetFlare(bool newFlare);
};

