#include <iostream>
#include <string>
#include <unordered_map>

#include "vertex.h"
#include "graph.h"
#include "algo.h"

using namespace std;

int main()
{
    Graph G;

    string inp;
    cout << "You will be constructing a graph." << endl;
    cout << "First, enter names for your vertices." << endl;
    cout << "The names must be unique and only 1 word each." << endl;
    cout << "When done, type 'ok'.\n" << endl;

    vector<string> helper;
		
    while(cin >> inp) {
        if (inp == "ok") break;
        // fill the graph's unordered hash map of vertices
        G.addVert(new Vertex(inp));
        // fill the helper vector as well
        helper.push_back(inp);
    }
    cout << endl;

    int graphsize = G.vertexMap().size();
    for (int i=0; i != graphsize; i++) {
        cout << i << " -> " << helper[i] << endl;
    }

    cout << "\nNow you'll use the indexes to establish "
            "one-way connections." << endl;
    cout << "0-5 connects the 0th vertex to the 5th vertex." << endl;
    cout << "7-9 connects the 7th vertex to the 9th vertex." << endl;
    cout << "24-49 connects the 24th vertex to the 49th, "
            "and so on." << endl;
    cout << "Create as many connections as you like. "
            "Type 'ok' when done.\n" << endl;

    // strip string input into two useful integers
    int u, v;
    string::size_type dashpos = 0;
    while (cin >> inp) {

        if (inp == "ok") break;

        //dashpos finds the position of the '-'.
        while(inp[dashpos] != NULL && inp[dashpos] != '-')
            dashpos++;

        //if dash was never entered,
        //or entry too short to be valid, ignore entry.
        if (dashpos == NULL || inp.size() <3) {
            cout << "(An invalid entry was ignored.)" << endl;
            continue;
        }

        u = stoi(inp.substr(0, dashpos));
        v = stoi(inp.substr(dashpos+1, inp.size()-(dashpos+1)));

        G.addConnection(helper[u], helper[v]);
    }

    displayGraph(G);

    cout << "\t---\nYour graph is complete. \nNow you have the option to execute "
            "\n* Breadth First Search (BFS), or \n* Depth First Search (DFS).\n" << endl;
    cout << "* To execute a BFS, specify your starting and target vertices." <<
            "\n-> 'bfs Paul John' executes a BFS starting from Paul, " <<
            "and looks for John." << endl << endl;
    cout << "* To execute a DFS, you specify the starting vertex only." <<
            "\n-> 'dfs Paul' executes a DFS starting from Paul." << endl;
    cout << "(Try both searches or type 'ok' to terminate the program.)" << endl;

    string src, trgt, rez;
    while (cin >> inp)
    {
        if (inp == "bfs")
        {
            cin >> src >> trgt;
            rez = G.bfs(G.vertexMap()[src], G.vertexMap()[trgt]);
            cout << endl;
            cout << rez << endl;
            continue;
        }

        else if (inp == "dfs")
        {
            cin >> src;
            rez = G.dfs(G.vertexMap()[src]);
            cout << endl;
            cout << rez << endl << endl;
            continue;
        }

        else if (inp == "ok")
        {
            break;
        }

        else
        {
            cout << "\nInvalid attempt, try again." << endl;
            continue;
        }
    }
    cout << "\n-fin-" << endl;
    return 0;
}
