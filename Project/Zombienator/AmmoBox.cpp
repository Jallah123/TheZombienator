#include "AmmoBox.h"
#include "Weapon.h"
#include "PlayableCharacter.h"


AmmoBox::AmmoBox() : Pickup()
{
}

AmmoBox::AmmoBox(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: Pickup(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
	SetSize(30, 32);
	SetImage("assets/images/box_normal_item.png");
}


AmmoBox::~AmmoBox()
{
}

void AmmoBox::DoAction(PlayableCharacter * pc)
{
	std::vector<Weapon*> weapons = pc->GetWeapons();
}
