#include <limits.h>
#include "Node.h"

class Edge
{
	private:
		int weight = INT_MAX / 2;
		Node* start = nullptr;
		Node* end = nullptr;
	public:
		Edge();
		Edge(Node* s, Node* f);
		~Edge();

		void SetWeight(int w) { this->weight = w; }
		Node* getNextNode(Node* node);

		int GetStart();
		int GetEnd();
};