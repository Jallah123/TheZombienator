#pragma once
#include "Character.h"
#include "Weapon.h"
#include "BubbleVisitor.h"
#include "KeyBinding.h"
#include <vector>
class GameScreen;
class PlayableCharacter
	: public Character
{
private:
	int currentWeaponIndex = 0;
	bool hasWeapon(Weapon* w);
protected:
	std::vector<Weapon*> weapons = {};
	Weapon* weapon = nullptr;
	bool isFlare = false;
	string imgUrl = "";
	KeyBinding* keyBinding = nullptr;
	GameScreen* gameScreen = nullptr;
public:
	PlayableCharacter();
	PlayableCharacter(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	virtual ~PlayableCharacter();
	void Init(string img_url, KeyBinding* _keyBinding);

	void TakeHit(int damage) override;
	void AddWeapon(Weapon* w);
	Weapon* GetWeapon() { return this->weapon; }
	std::vector<Weapon*> GetWeapons() { return this->weapons; }

	int const AmountOfWeapons() { return weapons.size(); }
	int const CurrentWeaponIndex() { return currentWeaponIndex; }

	KeyBinding* getKeyBinding() { return keyBinding; };

	void SetWeapon(Weapon* w);
	void NextWeapon();
	void PreviousWeapon();
	void Teleport(SDL_Renderer* ren);
	void SetFlare(bool newFlare);
	void Accept(BubbleVisitor* visitor) { visitor->Visit(this); };
	string getImgUrl() { return imgUrl; };
	void SetGameScreen(GameScreen* _gameScreen) { gameScreen = _gameScreen; };
	GameScreen* GetGameScreen() { return gameScreen; };
};

