#include "Vertex.h"

Vertex::Vertex(std::string vertexName, Vertex* v1, Vertex* v2, Vertex* v3, Vertex* v4, Vertex* v5, Vertex* v6, Vertex* v7, Vertex* v8): name(vertexName)
{
	if(v1 != 0)
		neigbours.push_back(v1);
	if(v2 != 0)
		neigbours.push_back(v2);
	if(v3 != 0)
		neigbours.push_back(v3);
	if(v4 != 0)
		neigbours.push_back(v4);
	if(v5 != 0)
		neigbours.push_back(v5);
	if(v6 != 0)
		neigbours.push_back(v6);
	if(v7 != 0)
		neigbours.push_back(v7);
	if(v8 != 0)
		neigbours.push_back(v8);
}

void Vertex::addNeighbour(Vertex* v)
{
	neigbours.push_back(v);
}

std::string Vertex::getName()
{
	return name;
}

std::vector<Vertex*> Vertex::getNeighbours()
{
	return neigbours;
}
