#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <map>

Graph::Graph() {}

Graph::~Graph() {}

void Graph::AddEdge(Node* n1, Node* n2)
{
	edges.push_back(new Edge(n1, n2));
}

void Graph::AddNode(int id, int x, int y)
{
	nodes.push_back(new Node(id, x, y));
}

void Graph::AddNode(Node* n)
{
	nodes.push_back(n);
}

void Graph::SetEdgeWeight(int begin, int end, int weight)
{
	for (auto& e : edges) {
		if (e->GetStart() == begin && e->GetEnd() == end ||
			e->GetStart() == end && e->GetEnd() == begin)
			e->SetWeight(weight);
	}
}