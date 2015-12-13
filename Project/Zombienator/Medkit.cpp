#include "Medkit.h"
#include "PlayableCharacter.h"


Medkit::Medkit()
	: Pickup()
{

}

Medkit::Medkit(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: Pickup(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
	SetSize(30, 32);
	SetImage("assets/images/box.png");
}


Medkit::~Medkit()
{
}

void Medkit::DoAction(PlayableCharacter * pc)
{
	pc->SetHealth(pc->GetMaxHealth());
}
