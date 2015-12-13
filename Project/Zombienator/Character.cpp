#pragma once
#include "Character.h"
#include "GameObjectFactory.h"
#include <iostream>

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
	std::cout << "hp " << health << "\n";
	if (IsDeath())
	{
		health = 0;
		OnDeath();
		Remove();
	}
}

void Character::OnDeath()
{
	GameObjectFactory::Instance()->CreateMedkit(this);
}




