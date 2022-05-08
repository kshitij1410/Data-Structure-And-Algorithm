#include <bits/stdc++.h>
using namespace std;

// undirected graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wei)
{
    adj[u].push_back({v, wei});
    adj[v].push_back({u, wei});
}

// calculate shortest distance using bfs
void shortestDistance(vector<pair<int, int>> adj[], int dist[], int v, int src)
{
    // dist,node
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int nodeDis = pq.top().first;
        int nodeVal = pq.top().second;
        pq.pop();
        for (auto nbr : adj[nodeVal])
        {
            int temp1 = nbr.first;  // nodeval
            int temp2 = nbr.second; // node dis
            if (dist[temp1] == INT_MAX)
            {
                int val = nodeDis + temp2;
                pq.push({val, temp1});
            }

            dist[temp1] = min(nodeDis + temp2, dist[temp1]);
        }
    }

}

int main()
{
    int v = 6;
    vector<pair<int, int>> adj[6];

    addEdge(adj, 1, 2, 2);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 4, 3, 3);
    addEdge(adj, 2, 5, 5);
    addEdge(adj, 3, 5, 1);

    int dist[v];

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX;

    shortestDistance(adj, dist, v,  1);

    cout << endl;
    for (int i = 1; i < v; i++)
        cout << dist[i] << " ";
    return 0;
}
