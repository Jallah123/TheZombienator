#include "Astar.h"
#include "Node.h"
#include "Graph.h"
#include <queue>
#include <functional> 

typedef pair< char, int > pii;

Astar::Astar() {}
Astar::~Astar() {}

int Astar::Compute(Graph* graph, int start, int end)
{
	int u, v, i, c, w;
	int n = graph->NodeSize();

	distance.resize(n);
	fill(distance.begin(), distance.end(), INT_MAX /2);
	
	std::priority_queue< pii, std::vector< pii >, std::greater< pii > > Q;

	Q.push(pii(0, start));
	distance[start] = 0;
  	parents[start] = start;//Begin at the start point

	while (!Q.empty()) {
		u = Q.top().second; // node
		c = Q.top().first; // node cost so far
		Node* node = graph->GetNode(u);
		Q.pop(); // remove the top item.

		if (distance[u] < c) continue;

		for (auto& n : node->Adjacent()) {
			Node* next = n;
			v = next->ID();//Node id
			w = node->Distance(v) ;//Node weight
			graph->SetEdgeWeight(u, v, w);
			//u = The node where we search the adjacent from
			if(distance[u] + w < distance[v]) {
				//printf("u-v{%d,%d} U{%d}, Weight{%d}, V{%d} \n ", u, v, distance[u], w, distance[v]);
				distance[v] = distance[u] + w;
				
				Q.push(pii(distance[v], v));
				parents[v] = u;
			}
		}
	}
	return distance[end];
}

std::queue<int> Astar::GetPath(int start, int end)
{
	std::queue<int> tmp;
	for (int v = end; v != start; v = parents[v])
		if (v != INT_MAX)
			tmp.push(v);
	tmp.push(start);
	PATH = tmp;

	return PATH;
}