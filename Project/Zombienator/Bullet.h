#pragma once
#include "GameObject.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "PlayableCharacter.h"

//Containers
class DrawContainer;
class MoveContainer;
class CollideContainer;
class GameObjectContainer;

//Behaviours
class DrawBehaviour;
class MoveBehaviour;
class CollideBehaviour;

class Bullet
	: public GameObject
{
protected:
	bool _hasCollision = false;
	bool _locked = false;
	float lifeTime = 25;
	SDL_Rect* target = nullptr;

	//Direction direction;
	PlayableCharacter* origin;

	DrawContainer* drawContainer;
	MoveContainer* moveContainer;
	CollideContainer* collideContainer;
	GameObjectContainer* gameObjectContainer;

	DrawBehaviour* drawBehaviour;
	MoveBehaviour* moveBehaviour;
	CollideBehaviour* collideBehaviour;

public:
	Bullet();
	virtual ~Bullet();
	void Init(DrawContainer* dc, MoveContainer* mc, CollideContainer* cc, GameObjectContainer* goc);
	
	void SetDrawBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);
	void SetCollideBehaviour(std::string name);

	void SetOrigin(PlayableCharacter* o) { 
		origin = o; 
		SetLookDir(o->GetLookDir()); 
		SetMoveDir(o->GetLookDir());
		posX = o->getPosX();
		posY = o->getPosY();
	}

	PlayableCharacter* GetOrigin() { return origin; }
	
	void SetLocked(bool l) { this->_locked = l; }
	bool IsLocked() { return this->_locked; }

	void SetCollision(bool c) { this->_hasCollision = c; }
	bool HasCollision() { return this->_hasCollision; }

	SDL_Rect* GetTarget() { return this->target; }
	void SetTarget(SDL_Rect* c) { this->target = c; }

	float GetLifeTime() { return lifeTime; }
	void DecreaseLifeTime(float time) { lifeTime -= time; }
};

