#pragma once
#include <vector>
#include <map>
#include <queue>
class Graph;

class Astar
{
	private:
		std::map<int, int> parents;
		std::vector<int> distance;
		std::queue<int> PATH;

		int pathIndex = 0;
	public:
		Astar();
		~Astar();

		int Compute(Graph* graph, int start, int end);
		std::queue<int> GetPath(int start, int end);
		void Print(Graph& graph, int start, int end);

		std::queue<int> Path() { return this->PATH; }
		int PathIndex() { return this->pathIndex; }
		void ResetPathIndex() { this->pathIndex = 0; }
		void UpPathIndex() { this->pathIndex++; }
};

