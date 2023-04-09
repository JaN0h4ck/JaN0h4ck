#include <iostream>
#include "Graph.h"


void calculateAndPrintPath(std::vector<Vertex*> pathToVerify) {
	std::vector<Vertex*> verticesVerified;

	for (size_t i = 0; i < pathToVerify.size(); i++) {
		bool found = false;
		for (size_t j = 0; j < verticesVerified.size(); j++)
			if (pathToVerify[i] == verticesVerified[j])
				found = true;
		if (!found) 
			verticesVerified.push_back(pathToVerify[i]);
	}

	// print path
	std::cout << "Path: ";
	for (size_t i = 0; i < verticesVerified.size(); i++) {
		std::cout << verticesVerified[i]->getName() << " ";
	}
	std::cout << std::endl;
}

void main() {
#pragma region Initialisation
	Vertex a("v1");
	Vertex b("v2");
	Vertex c("v3");
	Vertex d("v4");
	Vertex e("v5");
	Vertex f("v6");
	Vertex g("v7");
	Vertex h("v8");

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
#pragma endregion

	std::vector<Vertex*> path = { &a, &b, &c, &b, &c, &g, &f, &e, &d, &g, &h, &a, &b, &d };

	calculateAndPrintPath(path);
}