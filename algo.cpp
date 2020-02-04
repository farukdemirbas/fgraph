#include <iostream>
#include "algo.h"

using std::vector;
using std::cout;
using std::endl;

void displayGraph(const Graph& G)
{
    cout << endl;
    int vertcount = G.getSize(); // total number of vertices
    int edgecount = 0;
    for (const auto& kv : G.vertexMap())
    {
		// adjacencies for current Vertex
		const auto& adj = kv.second->adj();

        // num of adj for current vert
        int adjcount = adj.size();

        cout << "* [" << kv.first << "] is connected to "
             << adjcount << " vertices: \n--> ";

        // display adjacents for current vert
		for (const auto& pVert : adj)
        {
            cout << "[" << pVert->name << "] ";
            edgecount++;
        }
        cout << endl << endl;

    }
    cout << "[" << vertcount << "] vertices and [" << edgecount << "] edges in total.\n" << endl;
}
