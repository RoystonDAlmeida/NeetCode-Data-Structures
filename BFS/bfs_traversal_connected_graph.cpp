#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>>& adj, int s)
{
    // Step 1: Initialise a queue
    queue<int> q;
    
    // Step 2: Initialise a vector 'visited' of adj size and its elements to false
    vector<bool> visited(adj.size(),false);
    
    // Push the element into the queue and mark it as visited
    q.push(s);
    visited[s]=1;
    
    // Step 3: Iterate over each element of the queue
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        cout<<cur<<"\t";
        
        for(int x:adj[cur])
        {
            // Traverse over the neighbors of 'cur'
            if(!visited[x])
            {
                // Visit the neighbors and push them into the queue
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
void addEdge(vector<vector<int>>& adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s); // Since undirected edges
}
int main()
{
    int V=5;
    vector<vector<int>> edges={{0,1}, {0,2}, {1,3}, {1,4}, {2,4}};
    
    // Create adjacency matrix of size 'V'
    vector<vector<int>> adj(V);
    for(auto &e:edges)
    {
        // Link the vertices withing an edge
        addEdge(adj, e[0],e[1]);
    }
    cout<<"\nBFS traversal from node:0"<<endl;
    bfs(adj,0);
    return 0;
}
