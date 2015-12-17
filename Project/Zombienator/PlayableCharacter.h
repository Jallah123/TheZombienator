#pragma once
#include "Character.h"
#include "Weapon.h"
#include <vector>
class GameScreen;
class PlayableCharacter
	: public Character
{
private:
	bool hasWeapon(Weapon* w);
protected:
	std::vector<Weapon*> weapons = {};
	Weapon* weapon = nullptr;
	bool isFlare = false;
	GameScreen* gameScreen = nullptr;
public:
	PlayableCharacter();
	PlayableCharacter(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	virtual ~PlayableCharacter();

	void TakeHit(int damage) override;
	void AddWeapon(Weapon* w);
	Weapon* GetWeapon() { return this->weapon; }
	std::vector<Weapon*> GetWeapons() { return this->weapons; }
	void SetWeapon(Weapon* w);
	void NextWeapon();
	void PreviousWeapon();
	void Teleport(SDL_Renderer* ren);
	void SetFlare(bool newFlare);
	void SetGameScreen(GameScreen* _gameScreen) { gameScreen = _gameScreen; };
	GameScreen* GetGameScreen() { return gameScreen; };
};

