#include <bits/stdc++.h>
using namespace std;

// directed graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
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

// -----------------------------------------------------more time complexity -------------------------------------
bool cycleDetectionHepler(vector<int> adj[], vector<int> &parent, vector<bool> &visited, int src)
{
    visited[src] = true;

    for (auto nbr : adj[src])
    {
        if (visited[nbr] == false)
        {
            parent[nbr] = src;
            if (cycleDetectionHepler(adj, parent, visited, nbr))
                return true;
        }
        else
        {
            int i = parent[src];
            while (i > 0)
            {
                if (nbr == i)
                    return true;
                i = parent[i];
            }
        }
    }

    return false;
}

bool cycleDetect(vector<int> adj[], int v)
{
    vector<bool> visited;
    vector<int> parent;
    for (int i = 0; i < v; i++)
    {
        visited.push_back(false);
        parent.push_back(-1);
    }

    for (int src = 1; src < v; src++)
    {
        if (cycleDetectionHepler(adj, parent, visited, src) == true)
            return true;
    }
    return false;
}

// ----------------------------------------------------------------------------------------------

//-------------------------------------------------------less time complexity than previous---------------

bool cycleDetectionHepler2(vector<int> adj[], vector<bool> visited2, vector<bool> &visited1, int src)
{
    visited1[src] = true;
    visited2[src] = true;
    for (auto nbr : adj[src])
    {
        if (visited1[nbr] == false)
        {

            if (cycleDetectionHepler2(adj, visited2, visited1, nbr))
                return true;
        }
        else
        {
            if(visited2[nbr]==true) return true;
        }
    }

    return false;
}

bool cycleDetect2(vector<int> adj[], int v)
{
    vector<bool> visited1;
    vector<bool> visited2;
    //int visited1[v];
    //memset(visited1,0,sizeof visited1);
    for (int i = 0; i < v; i++)
    {
        visited1.push_back(false);
        visited2.push_back(false);
    }

    for (int src = 1; src < v; src++)
    {

        if (cycleDetectionHepler2(adj, visited2, visited1, src))
            return true;
    }
    return false;
}
// ----------------------------------------------------------------------------------------------------------

int main()
{
    int v = 10;
    vector<int> adj[10];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 3, 6);
    addEdge(adj, 6, 5);
    addEdge(adj, 7, 2);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 9);
    addEdge(adj, 9, 7);
    cout << cycleDetect2(adj, v);

    return 0;
}
