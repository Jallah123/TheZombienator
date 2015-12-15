#include "Node.h"
#include <math.h>

Node::Node(int ID, int x, int y) : id(ID)
{
	Position(x, y);
	Size(32, 32);
}
Node::~Node() {}

void Node::Position(int x, int y)
{
	destRect.x = x;
	destRect.y = y;
	Size(10, 10);
}

void Node::Size(int w, int h)
{
	destRect.w = w;
	destRect.h = h;
}

double Node::Distance(int nextID)
{
	Node* n = nullptr;
	for (auto& e : edges) {
		if (e->ID() == nextID)
			n = e;
	}
	if (n == nullptr) return -1;
	SDL_Rect r = n->getDestRect();
	return sqrt(pow(r.x - destRect.x, 2) + pow(r.y - destRect.y, 2));
}