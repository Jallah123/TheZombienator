#pragma once
#include "ZombieState.h"
#include <vector>
#include "Node.h"
#include "Character.h"

class ZombieWalkingState :
	public ZombieState
{
public:
	ZombieWalkingState();
	~ZombieWalkingState();
	void CheckState();
	void Update(float dt);
private:
	Node* GetClosestNodeNearTarget(Character* target, vector<Node>& nodes);
	Node* GetCheapestNode(vector<Node*>& nodes);
	void CalculatePath();
};

