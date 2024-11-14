// Program to perform DFS traversal of a connected undirected graph

#include<iostream>
#include<vector>

using namespace std;

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    // Mark 's' as visited
    visited[s]=1;
    
    cout<<s<<"\t";
    
    for(int v:adj[s])
    {
        if(visited[v]==false)
        {
            // Repeat the process of visiting v, by recursion
            DFSRec(adj,visited,v);
        }
    }
}

void DFS(vector<vector<int>> &adj, int s)
{
    vector<bool> visited(adj.size(), 0);    // Keep a track of the vertex(index) which are visited
    DFSRec(adj, visited,s);
}

void addEdge(vector<vector<int>> &adj, int s, int t)
{
    // Add the edge s or t at s or t
    adj[s].push_back(t);
    adj[t].push_back(s);
}
int main()
{
    int V=5;
    vector<vector<int>> adj(V);
    
    // Define the vector containing edges
    vector<vector<int>> edges={{1,2}, {1,0}, {2,0}, {2,3}, {2,4}};
    
    for(auto &e:edges)
    {
        addEdge(adj,e[0],e[1]);
    }
    
    // The source node is 1 
    int s=1;
    cout<<"\n DFS from the start node:"<<endl;
    DFS(adj, s);
    return 0;
}
