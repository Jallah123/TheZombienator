#pragma once
#include "Character.h"
#include "Weapon.h"
#include "KeyBinding.h"

class PlayableCharacter
	: public Character
{
private:
	bool hasWeapon(Weapon* w);
protected:
	std::vector<Weapon*> weapons = {};
	Weapon* weapon = nullptr;
	bool isFlare = false;
public:
	PlayableCharacter();
	~PlayableCharacter();
	KeyBinding* keyBinding = nullptr;
	void Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer * actionC, CollideContainer* collideC, GameObjectContainer * gameObjectC, SDL_Renderer * ren, string img_url, KeyBinding* _keyBinding);
	void TakeHit(int damage) override;
	void AddWeapon(Weapon* w);
	Weapon* GetWeapon() { return this->weapon; }
	void SetWeapon(Weapon* w);
	void NextWeapon();
	void PreviousWeapon();
	void Teleport(SDL_Renderer* ren);
	void SetFlare(bool newFlare);
};

