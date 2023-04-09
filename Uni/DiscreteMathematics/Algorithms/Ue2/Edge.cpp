#include "Edge.h"

Edge::Edge(Vertex* v1, Vertex* v2): vertex1(v1), vertex2(v2)
{
    name = "[" + v1->getName() + ", " + v2->getName() + "]";
}

std::string Edge::getName()
{
    return name;
}

Vertex* Edge::getVertex1()
{
    return vertex1;
}

Vertex* Edge::getVertex2()
{
    return vertex2;
}
