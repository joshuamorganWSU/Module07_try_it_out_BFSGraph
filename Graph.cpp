#include "Graph.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdint>
#include <queue>
#include <set>


using std::list;
using std::ifstream;
using std::invalid_argument;


Graph::Graph(std::string filename) {
	ifstream input;
	input.open(filename);
	if (!input) {
		throw invalid_argument("Could not read file");
	}

	input >> numNodes;
	adjList = new list<int>[numNodes];
	for (int i = 0; i < numNodes; i++) {
		int value;
		
		input >> value;
		while (value >= 0) {
			
			adjList[i].push_back(value);
			input >> value;
		}
	}
	
	printBFT(std::cout);

	
}


std::ostream& Graph::printBFT(std::ostream& out) {


	std::queue<int>	frontierQueue;
	std::set<int> discoveredSet;


	frontierQueue.push(adjList->front());			// Enqueue startV in frontierQueue
	discoveredSet.insert(adjList->front());			// Add startV to discoveredSet

	while (!(frontierQueue.empty())) {
		int currentV = frontierQueue.front();
		frontierQueue.pop();

		// "Visit" currentV (what am I printing exactly? just the nodes?)
		out  << currentV << " -> ";
		


		int cur = currentV;
		for (list<int>::iterator listIt = adjList[cur].begin(); listIt != adjList[cur].end(); listIt++) {

			if (!discoveredSet.count(*listIt)) {

				frontierQueue.push(*listIt);
				discoveredSet.insert(*listIt);
			}
		}
	}

	return out;
}
