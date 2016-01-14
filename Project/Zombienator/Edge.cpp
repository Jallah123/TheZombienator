#include "Edge.h"

Edge::Edge() {}
Edge::Edge(Node* s, Node* f) : start(s), end(f) {}
Edge::~Edge() {}

Node* Edge::getNextNode(Node* n)
{
	if (n == start)
		return end;
	return start;
}

int Edge::GetStart()
{
	if (start != nullptr) return start->ID();
	return -1;
}

int Edge::GetEnd()
{
	if (end != nullptr) return end->ID();
	return -1;
}
