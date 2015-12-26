#include "AmmoBox.h"
#include "Weapon.h"
#include "PlayableCharacter.h"
#include "NumberUtility.h"

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
	std::vector<Weapon*> notFullWeapons = {};
	//Find weapons where we can give ammo too
	for (auto& w : weapons) {
		if (!w->HasMaxAmmo()) {
			notFullWeapons.push_back(w);
		}
	}
	if (notFullWeapons.size() == 0) return;
	//Only continue if their are weapons to give ammo to
	int dice_roll = NumberUtility::RandomNumber(0, notFullWeapons.size() - 1);
	notFullWeapons.at(dice_roll)->SetMaxAmmo();
}
