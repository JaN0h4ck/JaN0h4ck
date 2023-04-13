#include "Vertex.h"

Vertex::Vertex(std::string vertexName): name(vertexName)
{

}

void Vertex::addNeighbour(Vertex* v)
{
	neighbours.push_back(v);
}

int Vertex::getDegree()
{
	return neighbours.size();
}

std::string Vertex::getName()
{
	return name;
}

std::vector<Vertex*> Vertex::getNeighbours()
{
	return neighbours;
}
