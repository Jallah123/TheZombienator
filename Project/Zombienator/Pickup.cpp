#include "Pickup.h"
#include "GameObjectContainer.h"
#include "Character.h"

Pickup::Pickup() : GameObject()
{
	SetCollideable(false);
}

Pickup::Pickup(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: GameObject(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
	SetCollideable(false);
	SetDrawBehaviour("SimpleDrawBehaviour");
   	SetCollideBehaviour("PickupCollideBehaviour");
	//SetFrames(1);
}


Pickup::~Pickup()
{
}

void Pickup::SetOrigin(Character * o)
{
	origin = o;
  	SetPosition(o->getPosX(), o->getPosY());
}
