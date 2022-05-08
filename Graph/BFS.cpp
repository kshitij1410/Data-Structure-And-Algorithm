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

// time- O(V+E)
void BFS(vector<int> adj[], int src, int vertex)
{
    queue<int> q;
    q.push(src);
    // vector<bool> visited(vertex,false);
    bool visited[vertex];
    for (int i = 0; i < vertex; i++)
        visited[i] = false;

    visited[src] = true;

    while (!q.empty())
    {
        int temp = q.front();

        q.pop();
        cout << temp << " ";

        for (auto x : adj[temp])
        {

            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

// time- O(V+E)
void BFSwithoutSrc(vector<int> adj[], int vertex)
{
    queue<int> q;

    bool visited[vertex];
    for (int i = 0; i < vertex; i++)
        visited[i] = false;

    for (int i = 0; i < vertex; i++)
    {
        if (visited[i] == false)
        {
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int temp = q.front();

                q.pop();
                cout << temp << " ";

                for (auto x : adj[temp])
                {

                    if (visited[x] == false)
                    {
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    int v = 4;
    vector<int> adj[v]; // 0,1,2,3

    // for undirected graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    // print adjacency list
    // printAdjacency(adj, v);
    BFS(adj, 0, 4);
    cout << "\n";
    BFSwithoutSrc(adj, 4);
    return 0;
}
