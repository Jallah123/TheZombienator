#ifndef CHARACTER_H
#define CHARACTER_H

#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "BehaviourFactory.h"
#include "DrawBehaviour.h"
#include "GameObject.h"
#pragma once

class GameObject;

class Character : public GameObject
{
protected:
	int damage;
	int health;
	int speed;
	//Containers
	AnimateContainer* animateContainer;
	DrawContainer* drawContainer;
	/*InputContainer inputContainer;
	CollideContainer collideContainer;*/

	//Behaviours
	DrawBehaviour* drawBehaviour;
public:
	Character();
	//Character(DrawContainer* drawC, AnimateContainer* animC);
	~Character();

	void TakeHit(int damage);
	int GetHealth() const { return health; }
	int GetSpeed() const { return speed; }
	int GetDamage() const { return damage; }

	void SetContainers(DrawContainer* drawC, AnimateContainer* animC) {
		drawContainer = drawC;
		animateContainer = animC;
	}

	void SetDrawBehaviour(std::string name) {
  		this->drawBehaviour = BehaviourFactory::Instance()->CreateDrawBehaviour(name, this);

		this->drawContainer->Add(drawBehaviour);
	}
};

#endif