#pragma once
#include "Vertex.h"
#include "Edge.h"


class Graph
{
	public:
	Graph(std::vector<Vertex*> verticesInGraph);


	std::vector<Vertex*> getVertices();
	std::vector<Edge*> getEdges();

	void recalculateEdges();
	
	private:
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
	void calculateEdges();
};

