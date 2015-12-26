#pragma once
#include "GameObject.h"

class Character;
class PlayableCharacter;

class Pickup :
	public GameObject
{
	Character* origin = nullptr;
public:
	Pickup();
	Pickup(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	~Pickup();

	void SetOrigin(Character* o);
	virtual void DoAction(PlayableCharacter* pc) = 0;
};

