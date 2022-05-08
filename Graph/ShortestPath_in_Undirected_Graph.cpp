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

// calculate shortest distance using bfs
void shortestDistance(vector<int> adj[], int dist[], int v, int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (auto nbr : adj[temp])
        {
            //this cndition check whether the node is visited or not
            //if it is not visited then push into queue 
            // if it is visited then only set the min value if it is possible.
            if (dist[nbr] == INT_MAX)
                q.push(nbr);

            // consider 1 unit distance in any node
            dist[nbr] = min(dist[nbr], dist[temp] + 1);
        }

        
    }
}

int main()
{
    int v = 9;
    vector<int> adj[9];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 7, 8);

    int dist[v];

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;

    shortestDistance(adj, dist, v, 0);

   for(int i=0;i<v;i++) cout<<dist[i]<<" ";
    // distance between 0-6
    // cout << dist[6] - dist[0] << " ";
    return 0;
}
