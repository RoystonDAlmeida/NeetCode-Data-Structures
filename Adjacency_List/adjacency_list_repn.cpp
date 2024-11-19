#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<vector<int>>& adj, int i, int j)
{
    adj[i].push_back(j);
    adj[j].push_back(i);    // Undirected edge
}

void printGraph(vector<vector<int>>& adj)
{
    for(int i=0;i<adj.size();i++)
    {
        cout<<i<<":";
        for(int j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int V=3;
    vector<vector<int>> edges={{0,1},{0,2},{1,2}};
    
    // Create an adjacency matrix
    vector<vector<int>> adj(V);
    
    for(auto &pair:edges)
    {
        addEdge(adj, pair[0], pair[1]);
    }
    
    printGraph(adj);
    
    return 0;
}
