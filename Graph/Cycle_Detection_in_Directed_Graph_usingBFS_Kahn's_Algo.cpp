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

// kahn's algo

void cycleDetectionUsingBFS(vector<int> adj[], int v)
{
    // step1: calcualte indegree
    int indeg[v];
    memset(indeg, 0, sizeof(indeg));

    for (int i = 0; i < v; i++)
    {
        for (auto x : adj[i])
        {
            indeg[x]++;
        }
    }

    // step2: push in queue those indegree is 0

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    // step3: pop queue one by one and decrease indegree of its nbr
    // if indegree of any node is 0 then push into queue

    int count = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        count++;

        for (auto nbr : adj[par])
        {
            indeg[nbr]--;

            if (indeg[nbr] == 0)
                q.push(nbr);
        }
    }

    if (count == v)
        cout << true;
    else
        cout << false;
}

int main()
{
    int v = 6;
    vector<int> adj[6];

    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 3, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 5, 2);
    cycleDetectionUsingBFS(adj, v);

    return 0;
}
