#pragma once

#include "vertex.h"
#include <unordered_map>

class Graph
{
private:
    int size; // number of vertices
	// name of, and a pointer to, each Vertex
    std::unordered_map<std::string, Vertex*> vertices;
public:
    Graph();
	virtual ~Graph();

    int getSize() const;
    void addVert(Vertex*);
    void addConnection(std::string, std::string);

    std::unordered_map<std::string, Vertex*> vertexMap() const;

    std::string bfs(Vertex* s, Vertex* t);
    std::string dfs(Vertex* s);
};