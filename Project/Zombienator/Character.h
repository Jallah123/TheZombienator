#pragma once
#include "GameObject.h"

//Containers
class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;

//Behaviours
class DrawBehaviour;
class AnimateBehaviour;
class MoveBehaviour;


class Character : 
	public GameObject
{
protected:
	int damage = 0;
	int health = 0;
	float speed = 0;
	int animationFrames = 0;

	//Containers
	AnimateContainer* animateContainer;
	DrawContainer* drawContainer;
	MoveContainer* moveContainer;
	InputContainer* inputContainer;
	/*CollideContainer collideContainer;*/

	//Behaviours
	DrawBehaviour* drawBehaviour;
	AnimateBehaviour* animateBehaviour;
	MoveBehaviour* moveBehaviour;
public:
	Character();
	virtual ~Character();

	void TakeHit(int damage);
	int GetHealth() const { return health; }
	float GetSpeed() const { return speed; }
	int GetDamage() const { return damage; }
	int GetFrames() const { return animationFrames; }

	void SetSpeed(float s) { speed = s; }
	void SetFrames(int f) { animationFrames = f; }


	void SetContainers(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, InputContainer* inputC);
	void SetDrawBehaviour(std::string name);
	void SetAnimateBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);

	InputContainer* GetInputContainer() { return inputContainer; }
};