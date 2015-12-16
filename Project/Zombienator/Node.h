#pragma once
#include <vector>
#include <SDL_render.h>


using std::vector;
using std::pair;
class Edge;

class Node
{
private:
	vector<Node*> edges = {};
	int id = -1;
	int weight = 0;
	SDL_Rect destRect = { 0,0,50,50 };
public:
	Node(int ID, int x, int y);
	~Node();

	vector<Node*> Adjacent() { return edges; }
	void AddEdge(Node* n) { edges.push_back(n); }

	int ID() { return id; }
	int Weight() { return weight; }
	SDL_Rect getDestRect() { return this->destRect; }

	void Position(int x, int y);
	void Size(int w, int h);
	double Distance(int nextID);
};

