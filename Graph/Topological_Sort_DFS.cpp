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

//difference between bool visited[]--- no need of & ,vector<bool>&visited-- need of &
void topologicalSortHelper(vector<int> adj[],bool visited[],stack<int>&st,int src)
{
    visited[src]=1;

   for(auto nbr: adj[src])
   {
       if(visited[nbr]==0)
       {
           topologicalSortHelper(adj,visited,st,nbr);
       }
   }
   
   st.push(src);

}

//This algo is only work in directed acyclic graph
//time-O(NO. OF NODE + NO.OF EDGE) ,SPACE -O(N)+O(N) , AUXILIARY SPACE -O(N) FOR RECURSION
void topologicalSort(vector<int> adj[], int v)
{
   stack<int>st;
   bool visited[v];
   memset(visited,0, sizeof(visited));
 
  for (int i=0;i<v;i++)
  {
      if(visited[i]==0)
      topologicalSortHelper(adj,visited,st,i);
    
  }
    
  while(!st.empty())
  {
      cout<<st.top()<<" ";
      st.pop();
  }

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
    
   topologicalSort(adj,v);

    return 0;
}
