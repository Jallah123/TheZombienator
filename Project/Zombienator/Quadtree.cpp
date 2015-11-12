#include "Quadtree.h"
#include <SDL_rect.h>
#include <stdio.h>
#include <iostream>
#include <SDL_render.h>
#include <algorithm>
#include "GameObject.h"

Quadtree::Quadtree() :
	isLeaf(true)
{
}

Quadtree::Quadtree(SDL_Rect rect) :
	rectangle(rect),
	currentLevel(0),
	isLeaf(true)
{
}

Quadtree::Quadtree(SDL_Rect _rect, unsigned int _numObjectsToGrow, int level) :
	rectangle(_rect),
	numObjectsToGrow(_numObjectsToGrow),
	isLeaf(true),
	currentLevel(level)
{
}


Quadtree::~Quadtree()
{
	if (!isLeaf)
		for (const auto& n : nodes)
			delete n;

}

void Quadtree::AddObject(GameObject *object)
{
	if (isLeaf) {
		//Add object to the leaf
		objects.push_back(object);
		bool reachedMaxObjects = (objects.size() == numObjectsToGrow);
		if (reachedMaxObjects) {
			//max is reached
			//create new leaves
			createLeaves();
			isLeaf = false;
		}
		return;
	}
	

	//loop all QuadTree nodes
	for (auto& n : nodes) {
		if (n->contains(object)) {
			//If object is within Node
			// add the object
			n->AddObject(object);
			return;
		}
	}

	objects.push_back(object);
}

void Quadtree::Clear()
{
	objects.clear();

	if (!isLeaf) {
		for (auto& n : nodes) {
			n->Clear();
		}
	}
}

vector<GameObject*> Quadtree::GetObjectsAt(double x, double y)
{
	if (isLeaf) {
		return objects;
	}

	vector<GameObject*> returnedObjects;
	vector<GameObject*> childObjects;

	if (!objects.empty())
		returnedObjects.insert(returnedObjects.end(), objects.begin(), objects.end());

	for (auto& n : nodes) {
		if (n->contains(x, y)) {
			childObjects = n->GetObjectsAt(x, y);
			returnedObjects.insert(returnedObjects.end(), childObjects.begin(), childObjects.end());
			break;
		}
	}

	return returnedObjects;
}

void Quadtree::Display(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 48, 10, 36, 255);
	SDL_RenderDrawRect(renderer, &rectangle);

	if (!isLeaf) {
		for (auto& n : nodes) {
			n->Display(renderer);
		}
	}
}

bool Quadtree::contains(GameObject *object)
{
	return SDL_HasIntersection(&rectangle, object->GetDestinationRect());
}

bool Quadtree::contains(double x, double y)
{
	return (x >= rectangle.x && x <= (rectangle.x + rectangle.w)) &&
		(y >= rectangle.y && y <= (rectangle.y + rectangle.h));
}

void Quadtree::createLeaves()
{
	if (currentLevel >= maxLevel) return;

	int w = rectangle.w / 2;
	int h = rectangle.h / 2;

	SDL_Rect NW = { rectangle.x, rectangle.y, w, h };
	SDL_Rect NE = { rectangle.x + w, rectangle.y, w, h };
	SDL_Rect SW = { rectangle.x, rectangle.y + h, w, h };
	SDL_Rect SE = { rectangle.x + w, rectangle.y + h, w, h };

	//create new leave nodes
	nodes.push_back(new Quadtree(NW, numObjectsToGrow, currentLevel + 1));
	nodes.push_back(new Quadtree(NE, numObjectsToGrow, currentLevel + 1));
	nodes.push_back(new Quadtree(SW, numObjectsToGrow, currentLevel + 1));
	nodes.push_back(new Quadtree(SE, numObjectsToGrow, currentLevel + 1));

	moveObjectsToLeaves();
}

void Quadtree::moveObjectsToLeaves()
{
	vector<GameObject*> toErase = {};
	for (auto& n : nodes) {
		for (auto& o : objects) {
			if (n->contains(o)) {
				n->AddObject(o);
				toErase.push_back(o);
			}
		}
	}
	for(auto& e : toErase)
		objects.erase(std::remove(objects.begin(), objects.end(), e), objects.end());
}