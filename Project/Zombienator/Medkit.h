#pragma once
#include "Pickup.h"
class Medkit :
	public Pickup
{
public:
	Medkit();
	Medkit(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	~Medkit();

	virtual void DoAction(PlayableCharacter* pc) override;
};

