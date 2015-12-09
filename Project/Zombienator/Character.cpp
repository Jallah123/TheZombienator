#pragma once
#include "Character.h"



Character::Character() : GameObject()
{
	SetSpeed(1);
}

Character::Character(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: GameObject(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
	SetSpeed(1);
}

Character::~Character()
{
	
}

void Character::TakeHit(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		Remove();
	}
}




