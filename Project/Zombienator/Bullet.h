#pragma once
//#include "MoveDirection.cpp"
#include "GameObject.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "PlayableCharacter.h"

//Containers
class DrawContainer;
class MoveContainer;
class CollideContainer;

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
	Character* target = nullptr;

	//MoveDirection direction;
	PlayableCharacter* origin;

	DrawContainer* drawContainer;
	MoveContainer* moveContainer;
	CollideContainer* collideContainer;

	DrawBehaviour* drawBehaviour;
	MoveBehaviour* moveBehaviour;
	CollideBehaviour* collideBehaviour;

	void SetContainers(DrawContainer* drawC, MoveContainer* moveC, CollideContainer* collideC);

public:
	Bullet();
	virtual ~Bullet();
	void Init(DrawContainer* dc, MoveContainer* mc, CollideContainer* cc);
	
	void SetDrawBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);
	void SetCollideBehaviour(std::string name);

	void SetOrigin(PlayableCharacter* o) { 
		origin = o; 
		SetMoveDir(o->GetMoveDir()); 
		posX = o->getPosX();
		posY = o->getPosY();
	}

	PlayableCharacter* GetOrigin() { return origin; }
	
	void SetLocked(bool l) { this->_locked = l; }
	bool IsLocked() { return this->_locked; }

	void SetCollision(bool c) { this->_hasCollision = c; }
	bool HasCollision() { return this->_hasCollision; }

	Character* GetTarget() { return this->target; }
	void SetTarget(Character* c) { this->target = c; }

	float GetLifeTime() { return lifeTime; }
	void DecreaseLifeTime(float time) { lifeTime -= time; }
};

