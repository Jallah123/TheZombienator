#include "ZombieWalkingState.h"
#include "ZombieStateFactory.h"
#include "GameObjectContainer.h"
#include "GameMath.h"
#include <limits>
#include <set>

ZombieWalkingState::ZombieWalkingState()
{
}


ZombieWalkingState::~ZombieWalkingState()
{
}


void ZombieWalkingState::CheckState()
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	if (target == nullptr && !target->IsDeath()) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, z));
		return;
	}
	else if (z->IsInAttackRadius(target)) {
		z->SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::ATTACKING, z));
		return;
	}
}

void ZombieWalkingState::Update(float dt)
{
	CalculatePath();
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	GameObjectContainer* goc = z->GetGameObjectContainer();
	float destX = target->getPosX();
	float destY = target->getPosY();

	// -- Get destination rect
	SDL_Rect* goRect = z->GetCollideRect();
	float newX = z->getPosX();
	float newY = z->getPosY();

	// -- Move directions
	bool left = destX + target->GetWidth() <= newX;
	bool right = destX >= newX + z->GetWidth();
	bool up = destY + (target->GetHeight()/2) <= newY;
	bool down = destY >= newY + (z->GetHeight() / 2);
	
	float speed = z->GetSpeed() * dt;

	z->SetMoveDir(Direction::NONE);

	// -- Move directions
	if (left) {
		z->SetMoveDir(Direction::WEST);
		z->SetLookDir(Direction::WEST);
		newX -= speed;
	}
	if (right) {
		z->SetMoveDir(Direction::EAST);
		z->SetLookDir(Direction::EAST);
		newX += speed;
	}
	if (up) {
		z->SetMoveDir(Direction::NORTH);
		z->SetLookDir(Direction::NORTH);
		newY -= speed;
	}
	if (down) {
		z->SetMoveDir(Direction::SOUTH);
		z->SetLookDir(Direction::SOUTH);
		newY += speed;
	}
	

	float finalX = newX;
	float finalY = newY;

	// -- Map Collision
	std::vector<GameObject*> gameObjects = goc->GetGameObjects();
	for (auto& g : gameObjects)
	{
		if (g != z) {
			goRect->x = static_cast<int>(newX + .5f);
			goRect->y = static_cast<int>(z->getPosY() + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalX = z->getPosX();

			goRect->x = static_cast<int>(z->getPosX() + .5f);
			goRect->y = static_cast<int>(newY + .5f + (goRect->h));
			if (SDL_HasIntersection(goRect, g->GetCollideRect()))
				finalY = z->getPosY();
		}
	}
	z->SetPosition(finalX, finalY);
	CheckState();
}

void ZombieWalkingState::CalculatePath() 
{
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();

	vector<Node> nodes = GetOwner()->GetGameObjectContainer()->GetMap()->GetNodes();
	Node* closestNodeNearSelf = GetClosestNodeNearTarget(z, nodes);
	Node* closestNodeNearTarget = GetClosestNodeNearTarget(target, nodes);

	vector<Node*> nodeQueue;
	set<Node*> openSet;
	vector<Node*> closedSet;

	closestNodeNearSelf->weight = 0;
	nodeQueue.push_back(closestNodeNearSelf);
	openSet.insert(closestNodeNearSelf);

	while (!nodeQueue.empty())
	{
		Node* cNode = GetCheapestNode(nodeQueue);
		nodeQueue.erase(find(nodeQueue.begin(), nodeQueue.end(), cNode));
		openSet.erase(cNode);

		if (cNode == closestNodeNearTarget)
		{
			vector<Node*> correctPath;
			while (cNode != closestNodeNearSelf)
			{
				correctPath.push_back(cNode);
				cNode = cNode->previousNode;
			}
			std::reverse(correctPath.begin(), correctPath.end());
			z->SetPath(correctPath);
		}
		closedSet.push_back(cNode);

		for (auto& reachableNode : cNode->reachableNodes)
		{
			if (find(closedSet.begin(), closedSet.end(), reachableNode.first) != closedSet.end())
			{
				continue;
			}
			int weight = cNode->weight + GameMath::Distance(*reachableNode.first->position, *closestNodeNearTarget->position) + GameMath::Distance(*cNode->position, *reachableNode.first->position);

			reachableNode.first->weight = GameMath::Distance(*reachableNode.first->position, *cNode->position);

			if (weight < reachableNode.first->weight) 
			{
				reachableNode.first->weight = weight;
				reachableNode.first->previousNode = cNode;
			}

			if (find(openSet.begin(), openSet.end(), reachableNode.first) == openSet.end())
			{
				nodeQueue.push_back(reachableNode.first);
				openSet.insert(reachableNode.first);
			}
		}
	}
}

Node* ZombieWalkingState::GetCheapestNode(std::vector<Node*>& nodes)
{
	Node* cheapest = nodes.at(0);
	for each (auto& node in nodes)
	{
		if (node->weight < cheapest->weight)
		{
			cheapest = node;
		}
	}
	return cheapest;
}

Node* ZombieWalkingState::GetClosestNodeNearTarget(Character* target, vector<Node>& nodes)
{
	Node* closestNode = &nodes.at(0);
	int closestRectDistance = INT_MAX;
	SDL_Rect* destRect = target->GetDestinationRect();

	for (auto& node : nodes)
	{
		SDL_Rect* currentRect = node.position;
		double distance = GameMath::Distance(*currentRect, *destRect);
		if (distance < closestRectDistance)
		{
			closestNode = &node;
			closestRectDistance = distance;
		}
	}
	return closestNode;
}
