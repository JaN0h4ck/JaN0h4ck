#pragma once
#include "Vertex.h"
#include <string>


class Edge
{
	public:
	Edge(Vertex* v1, Vertex* v2);

	std::string getName();
	Vertex* getVertex1();
	Vertex* getVertex2();

private:
	std::string name;
	Vertex* vertex1;
	Vertex* vertex2;
};

