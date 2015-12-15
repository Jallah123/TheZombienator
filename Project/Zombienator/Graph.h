#pragma once
#include <vector>

using std::vector;

class Edge;
class Node;

class Graph
{
	private:
		vector<Node*> nodes{};
		vector<Edge*> edges{};
	public:
		Graph();
		~Graph();

		void AddEdge(Node* n1, Node* n2);
		void AddNode(int id, int x, int y);
		void AddNode(Node* n);
		void CreateGraph();

		int NodeSize() { return nodes.size(); }
		int EdgesSize() { return edges.size(); }

		void SetEdgeWeight(int begin, int end, int weight);
		Node* GetNode(int i) { return nodes.at(i); }
		Node* GetRandomNode();

		vector<Node*> GetNodes() { return this->nodes; }
};

