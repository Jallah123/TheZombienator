#pragma once
//#include "MoveDirection.cpp"
#include "GameObject.h"

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

	DrawBehaviour* drawBehaviour;
	MoveBehaviour* moveBehaviour;

public:
	Bullet();
	virtual ~Bullet();

	void SetContainers(DrawContainer* drawC, MoveContainer* moveC);
	void SetDrawBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);

	void SetOrigin(PlayableCharacter* o) { this->origin = o; }
};

