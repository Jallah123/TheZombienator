#pragma once
//#include "MoveDirection.cpp"
#include "GameObject.h"
#include "DrawContainer.h"
#include "MoveContainer.h"
#include "CollideContainer.h"
#include "CollideBehaviour.h"

class DrawContainer;
class MoveContainer;

class PlayableCharacter;
class DrawBehaviour;
class MoveBehaviour;

class Bullet
	: public GameObject
{
protected:

	//MoveDirection direction;
	PlayableCharacter* origin;

	DrawContainer* drawContainer;
	MoveContainer* moveContainer;
	CollideContainer* collideContainer;

	DrawBehaviour* drawBehaviour;
	MoveBehaviour* moveBehaviour;
	CollideBehaviour* collideBehaviour;

	void Init(DrawContainer* dc, MoveContainer* mc, CollideContainer* cc);
public:
	Bullet();
	virtual ~Bullet();

	void SetContainers(DrawContainer* drawC, MoveContainer* moveC, CollideContainer* collideC);
	void SetDrawBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);
	void SetCollideBehaviour(std::string name);

	void SetOrigin(PlayableCharacter* o) { this->origin = o; }
	PlayableCharacter* GetOrigin() { return origin; }
};

