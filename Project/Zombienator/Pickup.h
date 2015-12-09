#pragma once
#include "GameObject.h"

//Containers
class DrawContainer;
class CollideContainer;
class GameObjectContainer;

//Behaviours
class DrawBehaviour;
class CollideBehaviour;
class Character;

class Pickup :
	public GameObject
{
protected:
	DrawContainer* drawContainer = nullptr;
	CollideContainer* collideContainer = nullptr;
	GameObjectContainer* gameObjectContainer = nullptr;

	Character* origin = nullptr;
public:
	Pickup();
	Pickup(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	~Pickup();

	void SetOrigin(Character* o);
};

