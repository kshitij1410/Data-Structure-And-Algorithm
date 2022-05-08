#include<bits/stdc++.h>
using namespace std;

//undirected graph

void addEdge(vector<int>adj[],int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);

}

//directed graph
void addEdgeD(vector<int>adj[],int u, int v)
{
  adj[u].push_back(v);

}


void  printAdjacency(vector<int>adj[],int v)
{
  for(int i=0;i<v;i++)
  {
      //list element
      for(auto x: adj[i])
      {
          cout<<x<<" ";
      }
      cout<<"\n";
  }


}


int main()
{
    int v=4;
    vector<int>adj[v];  //0,1,2,3

    //for undirected graph
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);

    // print adjacency list
    printAdjacency(adj,v);


   //for directed graph
    addEdgeD(adj,0,1);
    addEdgeD(adj,0,2);
    addEdgeD(adj,2,1);
    addEdgeD(adj,1,3);


    printAdjacency(adj,v);





    return 0;
}

/*
 int vertex,edge;
 cin>>vertex>>edge;
 vector<int>adj[vertex+1];  // for 1 based indexing 
 
 //for undirected graph
  for(i=0;i<edge;i++)
  { 
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);

  }

   //for weighted graph
   vector<pair<int,int>>adj1[vertex+1];

  for(i=0;i<edge;i++)
  { 
      int u,v,w;
      cin>>u>>v>>w;
      adj1[u].push_back({v,w});
      adj1[v].push_back({u,w});

  }


   return 0;



*/