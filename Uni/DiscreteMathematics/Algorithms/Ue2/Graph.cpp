#include "Graph.h"

Graph::Graph(std::vector<Vertex*> verticesInGraph) : vertices(verticesInGraph)
{
	calculateEdges();
}

std::vector<Vertex*> Graph::getVertices()
{
    return vertices;
}

std::vector<Edge*> Graph::getEdges()
{
	return edges;
}

void Graph::recalculateEdges()
{
	edges.clear();
	calculateEdges();
}

void Graph::calculateEdges()
{
	for (size_t i = 0; i < vertices.size(); i++)
	{
		std::vector<Vertex*> neighbours = vertices[i]->getNeighbours();
		for (size_t j = 0; j < neighbours.size(); j++)
		{
			//prevent double edges
			bool edgeExists = false;
			for (size_t k = 0; k < edges.size(); k++)
			{
				Vertex* startVertex = edges[k]->getVertex1();
				Vertex* endVertex = edges[k]->getVertex2();
				if ((startVertex == vertices[i] || endVertex == vertices[i]) && (endVertex == neighbours[j] || endVertex == neighbours[j]))
				{
					edgeExists = true;
					break;
				}
			}
			if (!edgeExists)
			{
				Edge* e = new Edge(vertices[i], neighbours[j]);
				edges.push_back(e);
			}
		}
	}
}
