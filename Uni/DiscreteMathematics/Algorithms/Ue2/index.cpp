#include <iostream>
#include "Graph.h"

/// <summary>
/// Searches for double Vertices in the list and removes every Vertex between them (plus one of the doubles)
/// </summary>
/// <param name="listWithDoubles">The list where double vertices are supposed to be removed</param>
void removeDoubles(std::vector<Vertex*>& listWithDoubles) {
	for (size_t i = 0; i < listWithDoubles.size(); i++) {
		for (size_t j = 0; j < listWithDoubles.size(); j++) {
			if (i != j && listWithDoubles[i] == listWithDoubles[j]) {
				listWithDoubles.erase(listWithDoubles.begin() + i, listWithDoubles.begin() + j);
			}
		}	
	}
}

/// <summary>
/// Extracts a valid path from a given List of vertices
/// </summary>
/// <param name="pathToVerify">List vertices that is supposed to be verified</param>
/// <param name="graphIsComplete"> Set to "true" if the graph is complete </param>
/// <returns>A List with a valid path (or a empty List)</returns>
std::vector<Vertex*> extractPathfromVertices(std::vector<Vertex*> pathToVerify, bool graphIsComplete = 0) {
	std::vector<Vertex*> verticesVerified;

	if (graphIsComplete) {
		removeDoubles(pathToVerify);
		verticesVerified = pathToVerify;
	} else {
		removeDoubles(pathToVerify);
		for (size_t i = 1; i < pathToVerify.size(); i++) {
			// Needs to be done this way to prevent Memory exception
			std::vector<Vertex*> neighbours = pathToVerify[i - 1]->getNeighbours();
			bool foundEdge = 0;
			for (size_t j = 0; j < neighbours.size(); j++) {
				if (pathToVerify[i] == neighbours[j]) {
					foundEdge = true;
					break;
				}
			}
			if (foundEdge) {
				verticesVerified.push_back(pathToVerify[i]);
				// First Element won't be in the list, if this isn't done
				if (i == 1) {
					verticesVerified.insert(verticesVerified.begin(), pathToVerify[i - 1]);
				}
			} else {
				pathToVerify.erase(pathToVerify.begin() + i);
				i--;
			}
		}
		if (verticesVerified.size() <= 1) {
			std::cout << "\nNo Path found!" << std::endl;
			return verticesVerified;
		}
	}

	// print path
	std::cout << "Path: ";
	for (size_t i = 0; i < verticesVerified.size(); i++) {
		std::cout << verticesVerified[i]->getName() << " ";
	}
	std::cout << std::endl;
	return verticesVerified;
}


int main() {
#pragma region Initialisation
	Vertex a("a");
	Vertex b("b");
	Vertex c("c");
	Vertex d("d");
	Vertex e("e");
	Vertex f("f");
	Vertex g("g");
	Vertex h("h");

	std::vector<Vertex*> vertices = {&a, &b, &c, &d, &e, &f, &g, &h};

	// add neighbours
	for (size_t i = 0; i < vertices.size(); i++)
	{
		for (size_t j = 0; j < vertices.size(); j++)
		{
			if (i != j)
			{
				vertices[i]->addNeighbour(vertices[j]);
			}
		}
	}

	for (size_t i = 0; i < vertices.size(); i++)
	{
		std::cout << vertices[i]->getName() << " has neighbours: ";
		std::vector<Vertex*> neighbours = vertices[i]->getNeighbours();
		for (size_t j = 0; j < neighbours.size(); j++)
		{
			std::cout << neighbours[j]->getName() << " ";
		}
		std::cout << std::endl;
	}

	Graph graph(vertices);

	std::vector<Edge*> edges = graph.getEdges();

	std::cout << "\nEdges: " << std::endl;

	for (size_t i = 0; i < edges.size(); i++)
	{
		std::cout << edges[i]->getName() << std::endl;
	}
	
	std::cout << std::endl;
#pragma endregion

	std::vector<Vertex*> path = { &a, &b, &c, &b, &c, &g, &f, &e, &d, &g, &h, &a, &b, &d };

	extractPathfromVertices(path, true);

	return 0;
}