#pragma once

#include <vector>
#include <string>

class Vertex
{
    std::vector<Vertex*> adjacents;
public:
    Vertex(std::string _name);

    std::string name;
    Vertex* parent;

    std::vector<Vertex*>& adj();

    void addConnection(Vertex);
    void addConnection(Vertex*);
};
