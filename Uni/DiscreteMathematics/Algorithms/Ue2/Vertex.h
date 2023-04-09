#pragma once
#include <vector>
#include <string>
class Vertex
{
	public:
		Vertex(std::string vertexName, Vertex* v1 = 0, Vertex* v2 = 0, Vertex* v3 = 0, Vertex* v4 = 0, Vertex* v5 = 0, Vertex* v6 = 0, Vertex* v7 = 0, Vertex* v8 = 0);

	void addNeighbour(Vertex* v);

	std::string getName();
	std::vector<Vertex*> getNeighbours();
	
	private:
	std::vector<Vertex*> neigbours;
	std::string name;
};

