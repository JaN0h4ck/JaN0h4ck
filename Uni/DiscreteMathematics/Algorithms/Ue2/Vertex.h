#pragma once
#include <vector>
#include <string>

class Vertex
{
	public:
	Vertex(std::string vertexName);

	void addNeighbour(Vertex* v);
	
	int getDegree();
	std::string getName();
	std::vector<Vertex*> getNeighbours();
	
	private:
	std::vector<Vertex*> neighbours;
	std::string name;
};

