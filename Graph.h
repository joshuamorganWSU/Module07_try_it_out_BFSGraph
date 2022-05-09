#pragma once
#include <list>
#include <string>


class Graph {

public:
	Graph(std::string);
	
	std::ostream& printBFT(std::ostream& out); //- outputs the graph using a breadth - first traversal

private:
	std::list<int>* adjList;
	int numNodes;
};