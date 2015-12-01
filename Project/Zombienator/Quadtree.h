#pragma once
#include <vector>
#include <SDL_rect.h>
#include <SDL_render.h>
using std::vector;

class GameObject;
struct SDL_Renderer;


//https://github.com/veeableful/Adaptive_Quadtree/blob/master/main.cpp
class Quadtree {

	enum Node {
		NW = 0,
		NE,
		SW,
		SE,
		NodeCount
	};

public:
	Quadtree();
	Quadtree(SDL_Rect rect);
	Quadtree(SDL_Rect rect, unsigned int numObjectsToGrow, int level);
	~Quadtree();

	void AddObject(GameObject *object);

	void Clear();

	vector<GameObject*>	GetObjectsAt(double x, double y);

	void Display(SDL_Renderer *renderer);

private:
	SDL_Rect rectangle={0,0,0,0};

	unsigned int numObjectsToGrow = 3;

	vector<GameObject*>	objects={};

	vector<Quadtree*> nodes={};

	bool isLeaf = false;

	bool contains(GameObject* object);

	bool contains(double x, double y);

	void createLeaves();

	void moveObjectsToLeaves();

	unsigned int maxLevel = 4;
	int currentLevel = 0;
};