#pragma once
#include "GameObject.h"
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
	Direction direction = Direction::NONE;
	bool _hasCollision = false;
	bool _locked = false;
	float lifeTime = 15;
	GameObject* target = nullptr;

	

	//Direction direction;
	PlayableCharacter* origin = nullptr;

	DrawContainer* drawContainer = nullptr;
	MoveContainer* moveContainer = nullptr;
	CollideContainer* collideContainer = nullptr;
	GameObjectContainer* gameObjectContainer = nullptr;

	DrawBehaviour* drawBehaviour = nullptr;
	MoveBehaviour* moveBehaviour = nullptr;
	CollideBehaviour* collideBehaviour = nullptr;

public:
	Bullet();
	virtual ~Bullet();
	void Init(DrawContainer* dc, MoveContainer* mc, CollideContainer* cc, GameObjectContainer* goc);
	virtual void SetBehaviours() = 0;
	virtual void ShakeScreen() {};
	void SetDrawBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);
	void SetCollideBehaviour(std::string name);
	void Remove();
	void SetOrigin(PlayableCharacter* o) { 
		origin = o; 
		SetLookDir(o->GetLookDir()); 
		SetMoveDir(o->GetMoveDir());
		posX = o->getPosX();
		posY = o->getPosY();
	}

	PlayableCharacter* GetOrigin() { return origin; }
	
	void SetLocked(bool l) { this->_locked = l; }
	bool IsLocked() { return this->_locked; }

	void SetCollision(bool c) { this->_hasCollision = c; }
	bool HasCollision() { return this->_hasCollision; }

	GameObject* GetTarget() { return this->target; }
	void SetTarget(GameObject* c) { this->target = c; }

	float GetLifeTime() { return lifeTime; }
	void DecreaseLifeTime(float time) { lifeTime -= time; }

	Direction GetDirection() { return this->direction; }
	void SetDirection(Direction d) { this->direction = d; }
};

