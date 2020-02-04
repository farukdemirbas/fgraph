#include "vertex.h"

Vertex::Vertex(std::string key) : name(key), parent(nullptr)
{}

std::vector<Vertex*>& Vertex::adj()
{
    return adjacents;
}

void Vertex::addConnection(Vertex newvert)
{
    Vertex* adjptr = &newvert;
    addConnection(adjptr);
}

void Vertex::addConnection(Vertex* newvert)
{
    //check if connection already exists.
	for (const auto& v : adjacents)
	{
        if (v == newvert)
            return;
    }
    adjacents.push_back(newvert);
}
