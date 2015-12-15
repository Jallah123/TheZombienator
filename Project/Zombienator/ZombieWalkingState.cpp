#include "ZombieWalkingState.h"
#include "ZombieStateFactory.h"
#include "GameObjectContainer.h"
#include "GameMath.h"
#include <limits>
#include <set>
#include "Astar.h"
#include <SDL_rect.h>
#include <algorithm>
#include "Graph.h"
#include "Node.h"
#include <vector>

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
	Zombie* z = GetOwner();
	Character* target = z->GetTarget();
	GameObjectContainer* goc = z->GetGameObjectContainer();
	float destX;
	float destY;
	SDL_Rect targetRect = *target->GetDestinationRect();

	// Calculate path
	vector<Node*>& nodes = z->GetGameObjectContainer()->GetMap()->GetGraph()->GetNodes();
	Graph* graph = z->GetGameObjectContainer()->GetMap()->GetGraph();
	Node* selfNode = GetClosestNodeNearTarget(z, nodes);
	Node* targetNode = GetClosestNodeNearTarget(target, nodes);
	Astar astar;

	if (GameMath::Distance(*z->GetDestinationRect(), *target->GetDestinationRect()) < GameMath::Distance(*z->GetDestinationRect(), selfNode->getDestRect()))
	{
		targetRect.x = target->GetDestinationRect()->x;
		targetRect.y = target->GetDestinationRect()->y;
	}
	else 
	{
		if (z->GetPath().empty())
		{
			astar.Compute(graph, selfNode->ID(), targetNode->ID());
			queue<int> path = astar.GetPath(selfNode->ID(), targetNode->ID());
			z->SetPath(path);
		}

		if (SDL_HasIntersection(&graph->GetNode(z->GetPath().front())->getDestRect(), z->GetDestinationRect()))
		{
			z->GetPath().pop();
		}

		targetRect.x = graph->GetNode(z->GetPath().front())->getDestRect().x;
		targetRect.y = graph->GetNode(z->GetPath().front())->getDestRect().y;
	}

	destX = targetRect.x;
	destY = targetRect.y;

	// -- Get destination rect
	SDL_Rect* goRect = z->GetCollideRect();
	float newX = z->getPosX();
	float newY = z->getPosY();

	// -- Move directions
	bool left = destX + target->GetWidth() <= newX;
	bool right = destX >= newX + z->GetWidth();
	bool up = destY + (target->GetHeight() / 2) <= newY;
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

Node* ZombieWalkingState::GetClosestNodeNearTarget(Character* target, vector<Node*>& nodes)
{
	Node* closestNode = nodes.at(0);
	int closestRectDistance = INT_MAX;
	SDL_Rect* destRect = target->GetDestinationRect();

	for (auto& node : nodes)
	{
		SDL_Rect& currentRect = node->getDestRect();
		double distance = GameMath::Distance(currentRect, *destRect);
		if (distance < closestRectDistance)
		{
			closestNode = node;
			closestRectDistance = distance;
		}
	}
	return closestNode;
}