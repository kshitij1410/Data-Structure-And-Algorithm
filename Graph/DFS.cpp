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

// //Time complexity - O(E+V)
// space use stack
void DFS(vector<int> adj[], int src, int vertex)
{
    stack<int> s;
    s.push(src);

    bool visited[vertex];

    for (int i = 0; i < vertex; i++)
        visited[i] = false;
    visited[src] = true;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        cout << temp << " ";

        for (auto x : adj[temp])
        {
            if (visited[x] == false)
            {
                s.push(x);
                visited[x] = true;
            }
        }
    }
}

// without use of stack O(1)
// Time complexity - O(E+V)
// Recursive approach


void DFS2(vector<int> adj[], int src, bool visited2[])
{
    
    visited2[src]=true;
    cout<<src<<" ";

    for(auto nbr: adj[src])
    {
        if(visited2[nbr]==false)
        {
            DFS2(adj,nbr,visited2);
        }
    }
}

int main()
{
    int v = 7;
    vector<int> adj[v]; // 0,1,2,3

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    // printAdjacency(adj, v);
    cout << endl;
    DFS(adj, 0, v);
    cout << endl;
   
   bool visited2[v];
    for(int i=0;i<v;i++)
    visited2[i]=false;

     DFS2(adj,0,visited2);

    return 0;
}
