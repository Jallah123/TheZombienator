#pragma once
#include "Character.h"
#include "Weapon.h"

class PlayableCharacter
	: public Character
{
private:
	bool hasWeapon(Weapon* w);
protected:
	std::vector<Weapon*> weapons = {};
	Weapon* weapon = nullptr;
	bool isFlare = false;
	string imgUrl = "";
public:
	PlayableCharacter();
	virtual ~PlayableCharacter();

	void TakeHit(int damage) override;
	void AddWeapon(Weapon* w);
	Weapon* GetWeapon() { return this->weapon; }
	void SetWeapon(Weapon* w);
	void NextWeapon();
	void PreviousWeapon();
	void Teleport(SDL_Renderer* ren);
	void SetFlare(bool newFlare);
	string getImgUrl() { return imgUrl; };
};

