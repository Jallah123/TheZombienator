#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <map>

Graph::Graph()
{
	//CreateGraph(); // Create the graph on init
}

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

void Graph::CreateGraph()
{
	vector<pair<int, int>> xys = { { 40, 130 }, { 250, 130 }, { 500, 150 }, { 375, 300 }, { 750, 130 }, { 250, 500 }, { 500, 400 }, { 500, 550 }, { 750, 350 } };
	vector<pair<int, vector<int>>> edg = { { 0, vector<int>{1,5} }, { 1, vector<int>{0,2,3} }, { 2, vector<int>{1,3,4} }, { 3, vector<int>{1,2,5,6} }, { 4, vector<int>{2,6,8} },	 
										 { 5, vector<int>{0,3,6} },	{ 6, vector<int>{3,4,5,7} }, { 7, vector<int>{6} },	{ 8, vector<int>{4} } };
	
	// Init 
	char letter[] = "a";
	int i = 0;

	// Add Node to vector nodes
	for (auto& xy : xys) {
		AddNode(i, xy.first, xy.second);
		letter[0] = static_cast<char>(letter[0] + 1);
		i++;
	}

	// Add Edge to vector edges
	for (auto& ed : edg) {
		for (auto& e : ed.second) {
			AddEdge(nodes.at(ed.first), nodes.at(e));
			nodes.at(ed.first)->AddEdge(nodes.at(e));
		}
	}
}

void Graph::SetEdgeWeight(int begin, int end, int weight)
{
	for (auto& e : edges) {
		if (e->GetStart() == begin && e->GetEnd() == end ||
			e->GetStart() == end && e->GetEnd() == begin)
			e->SetWeight(weight);
	}
}