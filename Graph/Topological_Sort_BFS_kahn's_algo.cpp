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
// This algo is only work in directed acyclic graph
// time-O(NO. OF NODE + NO.OF EDGE) ,SPACE -O(N)+O(N) , AUXILIARY SPACE -O(N) FOR RECURSION
vector<int> topologicalSortUsingBFS(vector<int> adj[], int v)
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

    vector<int> ans;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        ans.push_back(par);

        for (auto nbr : adj[par])
        {
            indeg[nbr]--;

            if (indeg[nbr] == 0)
                q.push(nbr);
        }
    }

    return ans;
}

int main()
{
    int v = 6;
    vector<int> adj[6];

    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 5, 2);
    vector<int> result = topologicalSortUsingBFS(adj, v);

    for (auto ans : result)
        cout << ans << " ";

    return 0;
}
