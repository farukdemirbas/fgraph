#include "graph.h"

using std::string;
using std::unordered_map;
using std::vector;
using std::to_string;

Graph::Graph() : size(0)
{}

Graph::~Graph()
{
}

void Graph::addVert(Vertex* newguy)
{
    // check whether vertex already exists in vertexMap.
    if (vertices.count(newguy->name) == 0)
    {
        vertices[newguy->name] = newguy;
        size++;
    }
}

void Graph::addConnection(string name1, string name2)
{
    // if both vertices already exist in the graph, connect name1 to name2.
    if (vertices.count(name1) == 1 && vertices.count(name2) == 1)
    {
        vertices[name1]->addConnection(vertices[name2]);
    }
}

std::unordered_map<std::string, Vertex*> Graph::vertexMap() const
{
    return vertices;
}

int Graph::getSize() const { return size; }

string Graph::bfs(Vertex* s, Vertex* t)
{
    //this function will return info about the path from s to t.
    //every reachable vertex will be assigned a parent and a level.
    //parental information will be used to construct a "shortest path".
    //and "level" will be the number steps needed to reach a particular vertex.
    //all relative to the specified starting point, Vertex* s.

    //parent and level hashmaps will work with the NAMES, not the objects.
    unordered_map<std::string, std::string> parent;
    unordered_map<std::string, int> level;

    //the starting vertex has no parent, and is reachable in 0 steps.
    parent[s->name] = "";
    level[s->name] = 0;

    //frontier is our current level of vertices.
    vector<Vertex*> frontier;
    frontier.push_back(s);

    //next is the next level. it is initially empty,
    //because we don't yet _know_ what exists on the next level.
    vector<Vertex*> next;

    //to iterate over the frontier
    vector<Vertex*>::size_type i, j;

    int l = 1; //the starting level

    //while frontier isn't empty
    while (frontier.size() > 0)
    {
        for (i=0; i!=frontier.size(); i++)
        {
            for (j=0; j!=frontier[i]->adj().size(); j++)
            {
                //if we haven't processed this vertex yet
                if (level.count(frontier[i]->adj()[j]->name) == 0)
                {
                    //looks a bit confusing.
                    //frontier[i]->adj()[j] is the pointer
                    //to the jth child of frontier[i].
                    //note that adj() returns a vector
                    //of pointers to that vertex's children.
                    parent[frontier[i]->adj()[j]->name] = frontier[i]->name;
                    //parent of frontier[i]'s child is frontier[i]
                    //(using the names and not the objects itself)

                    level[frontier[i]->adj()[j]->name] = l;

                    //we put the object pointer itself and not just the name
                    //because we'll need info about its neighbors
                    next.push_back(frontier[i]->adj()[j]);
                }
            }
        }

        l++; //done with this level, advancing.
        frontier = next; //so our new frontier is "next".
        next.clear(); //and our new "next" is empty.
    }

    string curr = t->name;
    string path = "";

    if (parent.count(curr) == 0)
    {
        return "No connection was found between given vertices.\n";
    }

    while (curr != "")
    {
        path += "[" + curr + "] <- ";
        curr = parent[curr];
    }

    //just trimming out the last " <- "
    path = path.substr(0, path.size()-4);

    string output;
    output = "* Steps required to reach [" + t->name + "] from ["+ s->name + "]: "
                + to_string(level[t->name]) + ".\n* A 'shortest path' is,\n"
                    + path + "\n";
    return output;
}

string Graph::dfs(Vertex* s)
{
    vector<Vertex*> stakk;
    unordered_map<string, bool> processed;

    stakk.push_back(s);

    Vertex* u = nullptr;

    string result = "Visited:";
    int vertcount = 0;

    while (stakk.size() > 0)
    {
        u = stakk.back();
        stakk.pop_back();

        if (processed.count(u->name) == 0)
        {
            processed[u->name] = true;
            result += " [" + u->name + "] ->";
            vertcount++;

            for (int i=0; i!=u->adj().size(); i++)
            {
                if (processed.count(u->adj()[i]->name) == 0)
                {
                    stakk.push_back(u->adj()[i]);
                }
            }
        }
    }

    result = result.substr(0, result.size()-3);
    result += "\nThere are " + to_string(vertcount)
            + " reachable vertices in total.";
    return result;
}

