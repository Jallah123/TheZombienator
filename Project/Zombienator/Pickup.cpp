#include "Pickup.h"
#include "GameObjectContainer.h"
#include "Character.h"

Pickup::Pickup()
{
}

Pickup::Pickup(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: GameObject(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
	//SetCollideBehaviour("");
	SetDrawBehaviour("AnimateBehaviour");
	SetFrames(1);
	gameObjectContainer->AddGameObject(this);
}


Pickup::~Pickup()
{
}

void Pickup::SetOrigin(Character * o)
{
	origin = o;
	SetPosition(o->getPosX(), o->getPosY());
}
