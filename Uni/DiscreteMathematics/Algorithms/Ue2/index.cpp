#include <iostream>
#include "Graph.h"

using std::vector, std::cout, std::endl;

/// <summary>
/// Searches for double Vertices in the list and removes every Vertex between them (plus one of the doubles)
/// </summary>
/// <param name="listWithDoubles">The list where double vertices are supposed to be removed</param>
void removeDoubles(vector<Vertex*>& listWithDoubles) {
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
vector<Vertex*> extractPathfromVertices(vector<Vertex*> pathToVerify, bool graphIsComplete = 0) {
	vector<Vertex*> verticesVerified;

	if (graphIsComplete) {
		removeDoubles(pathToVerify);
		verticesVerified = pathToVerify;
	} else {
		removeDoubles(pathToVerify);
		for (size_t i = 1; i < pathToVerify.size(); i++) {
			// Needs to be done this way to prevent Memory exception
			vector<Vertex*> neighbours = pathToVerify[i - 1]->getNeighbours();
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
	cout << "Path: ";
	for (size_t i = 0; i < verticesVerified.size(); i++) {
		cout << verticesVerified[i]->getName() << " ";
	}
	cout << endl;
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

	vector<Vertex*> vertices = {&a, &b, &c, &d, &e, &f, &g, &h};

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
		cout << vertices[i]->getName() << " has neighbours: ";
		vector<Vertex*> neighbours = vertices[i]->getNeighbours();
		for (size_t j = 0; j < neighbours.size(); j++)
		{
			cout << neighbours[j]->getName() << " ";
		}
		cout << endl;
	}

	Graph graph(vertices);

	vector<Edge*> edges = graph.getEdges();

	cout << "\nEdges: " << endl;

	for (size_t i = 0; i < edges.size(); i++)
	{
		cout << edges[i]->getName() << endl;
	}
	
	cout << endl;
#pragma endregion

	vector<Vertex*> path = { &a, &b, &c, &b, &c, &g, &f, &e, &d, &g, &h, &a, &b, &d };

	extractPathfromVertices(path, true);

	return 0;
}