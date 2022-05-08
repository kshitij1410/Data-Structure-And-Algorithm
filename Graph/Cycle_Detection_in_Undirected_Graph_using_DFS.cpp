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
    for (int i = 0; i < v; i++)
    {
        // list element
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

bool cycleDetectionHepler(int src, int parent, bool visited[],vector<int> adj[])
{
    visited[src] = true;

    for (auto nbr : adj[src])
    {
        if (visited[nbr] == false)
        {
            return cycleDetectionHepler(nbr, src, visited,adj);
        }
        else if (visited[nbr] == true and parent != nbr)
        {
            return true;
        }
        else{
            //do nothing
        }
    }

    return false;
}

bool cycleDetection(vector<int> adj[], bool visited[], int v)
{
    // the graph is divided into components
    bool ans = false;
    for (int i = 1; i < v; i++)
    {
        bool res = false;
        if (visited[i] == false)
        {
            res = cycleDetectionHepler(i, -1, visited,adj);
        }
        ans = ans or res;
    }
    return ans;
}

int main()
{
    int v = 9;
    vector<int> adj[9];

    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 8);
    addEdge(adj, 6, 7);
    addEdge(adj, 8, 7);

    bool visited[v];
    for (int i = 1; i < v; i++)
        visited[i] = false;

    cout << cycleDetection(adj, visited, v);

    return 0;
}
