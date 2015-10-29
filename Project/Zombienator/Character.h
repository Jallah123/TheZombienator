#pragma once
#include "GameObject.h"
#include <vector>
//Containers
class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;
class ActionContainer;

//Behaviours
class DrawBehaviour;
class AnimateBehaviour;
class MoveBehaviour;
class ActionBehaviour;


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
	ActionContainer* actionContainer;
	/*CollideContainer collideContainer;*/

	//Behaviours
	DrawBehaviour* drawBehaviour;
	AnimateBehaviour* animateBehaviour;
	MoveBehaviour* moveBehaviour;
	//Character can have multiple actions
	std::vector<ActionBehaviour*> actionBehaviours;

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


	void SetContainers(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, InputContainer* inputC, ActionContainer* actionC);
	void SetDrawBehaviour(std::string name);
	void SetAnimateBehaviour(std::string name);
	void SetMoveBehaviour(std::string name);
	void SetActionBehaviour(std::string name);

	InputContainer* GetInputContainer() { return inputContainer; }
};