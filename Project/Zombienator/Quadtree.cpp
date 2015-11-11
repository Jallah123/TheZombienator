#include "Quadtree.h"
#include <SDL_rect.h>
#include <stdio.h>
#include <SDL_render.h>
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
	/*SDL_Rect rect;
	rect.x = left;
	rect.y = top;
	rect.w = right - left;
	rect.h = down - top;*/
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
	/*SDL_Rect* r2 = object->GetDestinationRect();
	return !(r2->x > (rectangle.x + rectangle.w) ||
		(r2->x + r2->w) < rectangle.x ||
		r2->y > (rectangle.y + rectangle.h) ||
		(r2->y + r2->h) < rectangle.y);
*/
	//return SDL_HasIntersection(&rectangle, object->GetDestinationRect());
	/*return 	object->left > left &&
		object->right < right &&
		object->top > top &&
		object->down < down;*/
}

bool Quadtree::contains(double x, double y)
{
	return (x >= rectangle.x && x <= (rectangle.x + rectangle.w)) &&
		(y >= rectangle.y && y <= (rectangle.y + rectangle.h));
	/*return 	(x >= left && x <= right) &&
		(y >= top && y <= down);*/
}

void Quadtree::createLeaves()
{
	if (currentLevel >= maxLevel) return;
	//nodes.reserve(4);
	//Quadtree  ( left, right, top, down );
	//Quadtree  (    0,  1024,   0,  768 ) ;
	//               x,     w,   y,    h
	int w = rectangle.w / 2;
	int h = rectangle.h / 2;

	SDL_Rect NW = { rectangle.x, rectangle.y, w, h };
	SDL_Rect NE = { w, rectangle.y, w, h };

	SDL_Rect SW = { rectangle.x, h, w, h };
	SDL_Rect SE = { w, h, w, h };

	nodes.push_back(new Quadtree(NW, numObjectsToGrow, currentLevel + 1));
	nodes.push_back(new Quadtree(NE, numObjectsToGrow, currentLevel + 1));
	nodes.push_back(new Quadtree(SW, numObjectsToGrow, currentLevel + 1));
	nodes.push_back(new Quadtree(SE, numObjectsToGrow, currentLevel + 1));


	//nodes[NW] = Quadtree(left, (left + right) / 2, top, (top + down) / 2, numObjectsToGrow);
	//nodes[NE] = Quadtree((left + right) / 2, right, top, (top + down) / 2, numObjectsToGrow);
	//nodes[SW] = Quadtree(left, (left + right) / 2, (top + down) / 2, down, numObjectsToGrow);
	//nodes[SE] = Quadtree((left + right) / 2, right, (top + down) / 2, down, numObjectsToGrow);
	moveObjectsToLeaves();
}

void Quadtree::moveObjectsToLeaves()
{
	for (int n = 0; n < NodeCount; ++n) {
		for (unsigned int m = 0; m < objects.size(); ++m) {
			if (nodes.at(n)->contains(objects[m])) {
				nodes.at(n)->AddObject(objects[m]);
				objects.erase(objects.begin() + m);
				--m;
			}
		}
	}
}