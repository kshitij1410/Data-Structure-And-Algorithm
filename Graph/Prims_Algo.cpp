#include <bits/stdc++.h>
using namespace std;

// undirected graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wei)
{
    adj[u].push_back({v, wei});
    adj[v].push_back({u, wei});
}


//Brute force approach
//O(N^2)
void primsAlgo(vector<pair<int, int>> adj[], int v)
{

    int key[v], parent[v];
    bool mst[v];

    for (int i = 0; i < v; i++)
    {
        mst[i] = false;
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    key[0] = 0;

    for (int edges = 0; edges < v-1; edges++)  //N-1 edges
    {

        // step1: check node which is min and not a part of mst
        int min = INT_MAX;
        int node = 0;
        for (int i = 0; i < v; i++)
        {
            if (mst[i] == false and key[i] < min)
            {
                min = key[i];
                node = i;
            }
        }
       
       mst[node]=true;
        // step2:traverse the node nbr and find min weight of adj node
        for (auto nbr : adj[node])
        {
            if (key[nbr.first] == INT_MAX || key[nbr.first] > nbr.second)
            {
                key[nbr.first] = nbr.second; //weight
                parent[nbr.first] = node;
            }
        }


    }

    for(int i=0;i<v;i++)
    {
        cout<<parent[i]<<" ";
    }
}

//---------------------------------------------------------------------------------------
//EFFICIENT APPROACH
//O(NLOGN)
void primsAlgoEfficient(vector<pair<int, int>> adj[], int v)
{
   
    //min heap
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    int key[v], parent[v];
    bool mst[v];

    for (int i = 0; i < v; i++)
    {
        mst[i] = false;
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    key[0] = 0;
   
   pq.push({0,0}); // wieght,node

    for (int edges = 0; edges < v-1; edges++)  //N-1 edges
    {

        // step1: check node which is min and not a part of mst
        int node=pq.top().second;
        pq.pop();
       
       mst[node]=true;
        // step2:traverse the node nbr and find min weight of adj node
        for (auto nbr : adj[node])
        {
            int weight=nbr.second;
            int keyVal=nbr.first;

            if (key[keyVal] == INT_MAX || key[keyVal] > weight)
            {
                key[keyVal] = weight; //weight
                parent[keyVal] = node;
                pq.push({weight,keyVal});
            }
        }


    }

    for(int i=0;i<v;i++)
    {
        cout<<parent[i]<<" ";
    }

}

int main()
{
    int v = 5;
    vector<pair<int, int>> adj[5];

    addEdge(adj, 0, 3, 6);
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 4, 2, 7);

    primsAlgo(adj, v);
    cout<<'\n';
    primsAlgoEfficient(adj, v);
    return 0;
}
