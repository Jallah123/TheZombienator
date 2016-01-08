#pragma once
#include "ZombieState.h"
#include <vector>
#include "Node.h"
#include "Character.h"

class ZombieWalkingState :
	public ZombieState
{
public:
	ZombieWalkingState() {};
	~ZombieWalkingState() {};
	void CheckState();
	void Update(float dt);
private:
	Node* GetClosestNodeNearTarget(Character* target, vector<Node*>& nodes);
	bool NodeIsInGoodDirection(SDL_Rect* destRect, Node* node);
	SDL_Rect GetDestination(float dt);
	Node* previousTargetNode = nullptr;
};