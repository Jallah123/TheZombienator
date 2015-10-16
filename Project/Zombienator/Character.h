#pragma once

#include "BehaviourFactory.h"
#include "AnimateBehaviour.h"
#include "DrawBehaviour.h"
#include "AnimateContainer.h"
#include "DrawContainer.h"
#include "GameObject.h"

class Character : 
	public GameObject
{
protected:
	int damage = 0;
	int health = 0;
	int speed = 0;
	int animationFrames = 0;
	//Containers
	AnimateContainer* animateContainer;
	DrawContainer* drawContainer;
	/*InputContainer inputContainer;
	CollideContainer collideContainer;*/

	//Behaviours
	DrawBehaviour* drawBehaviour;
	AnimateBehaviour* animateBehaviour;
public:
	Character();
	//Character(DrawContainer* drawC, AnimateContainer* animC);
	~Character();

	void TakeHit(int damage);
	int GetHealth() const { return health; }
	int GetSpeed() const { return speed; }
	int GetDamage() const { return damage; }
	int GetFrames() const { return animationFrames; }

	void SetFrames(int f) { animationFrames = f; }


	void SetContainers(DrawContainer* drawC, AnimateContainer* animC);
	void SetDrawBehaviour(std::string name);
	void SetAnimateBehaviour(std::string name);
};