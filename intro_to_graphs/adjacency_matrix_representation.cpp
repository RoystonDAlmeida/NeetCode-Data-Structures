#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>>& mat, int i, int j)
{
    // Function to add an edge from i->j and j->i
    mat[i][j]=1;
    mat[j][i]=1;    // SIcne, undirected graph
}

void printGraph(vector<vector<int>>& mat)
{
    int V=mat.size();   // Will assign a size=number of occupied indices
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    // Create a 2D matrix(vector<vector<int>>) graph of 4 vertices and edges
    // Initialise each entry to 0
    int V=4;
    vector<vector<int>> mat(V, vector<int> (V,0));
    
    // Add edges in the graph
    addEdge(mat, 0, 1);
    addEdge(mat, 0,2);
    addEdge(mat, 1 , 2);
    addEdge(mat,2,3);
    
    cout<<"\nElements of the graph are:"<<endl;
    printGraph(mat);
    
    return 0;
}
