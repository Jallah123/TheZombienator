#pragma once
#include "Pickup.h"
class AmmoBox :
	public Pickup
{
public:
	AmmoBox();
	AmmoBox(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	~AmmoBox();

	virtual void DoAction(PlayableCharacter* pc) override;
};

