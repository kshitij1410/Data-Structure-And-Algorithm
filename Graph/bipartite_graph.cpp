#include <bits/stdc++.h>
using namespace std;

// undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAdjacency(vector<int> adj[], int v)
{
    for (int i = 1; i < v; i++)
    {
        // list element
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

bool dfs(vector<int> adj[], int src, vector<int> &color)
{
    //src- starting node
    if (color[src] == -1)
        color[src] = 1;

    for (auto nbr : adj[src])
    {
        if (color[nbr] == -1)
        {
            //opposite color value
            color[nbr] = 1 - color[src];
            
            if(dfs(adj, nbr, color)==false) return false;
        }
        //both nbr node have same color value
        else if (color[src] == color[nbr])
            return false;
        else
        {
            //opposite color value of nbr
            //do nothing
        }
    }

    return true;
}

bool checkBiPartite(vector<int> adj[], int v)
{
    vector<int> color;
    for (int i = 0; i < v; i++)
        color.push_back(-1);

    // this method also for components of graph
    for (int src = 1; src < v; src++)
    {
        //unvisited node
        if (color[src] == -1)
        {
            //if any one condition is not sactifise then return false
            if (dfs(adj, src, color) == false)
                return false;
        }
    }

    return true;
}

int main()
{
    int v = 9;
    vector<int> adj[9];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 2, 6);
    addEdge(adj, 5, 6);

    if (checkBiPartite(adj, v))
        cout << "1";
    else
        cout << "0";

    return 0;
}
