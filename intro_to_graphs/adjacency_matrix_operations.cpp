// C++ program to add and remove vertex in adjacency matrix
#include<iostream>
#include<vector>

using namespace std;

class Graph
{
    private:
        int g[10][10];
        int n;
    public:
            Graph(int size)
            {
                n=size;
                
                // Initialise the degree of each vertex to 0 
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        g[i][j]=0;
                    }
                }
            }
            
            void addEdge(int x, int y)
            {
                // Add edge between 2 vertices
                if((x>=n) || (y>n))
                {
                    cout<<"\nVertex not present";
                }
                if(x==y)
                {
                    cout<<"\nSame vertex";
                }
                else
                {
                    // Connect g[x][y] and g[y][x]
                    g[x][y]=g[y][x]=1;// SInce, undirected graph
                }
            }
            
            void removeEdge(int x, int y)
            {
                if((x>=n) || (y>n))
                {
                    cout<<"\nVertex nor present";
                }
                if(x==y)
                {
                    cout<<"\nSame vertex";
                }
                else
                {
                    g[x][y]=g[y][x]=0;
                }
            }
            void displayAdjacencyMatrix()
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        cout<<g[i][j]<<"\t";
                    }
                    cout<<endl;
                }
            }
            
            void addVertex()
            {
                // Increase the size of the matrix
                n++;
                
                for(int i=0;i<n;i++)
                {
                    // Adding row and column indices related to the element
                    g[i][n-1]=0;
                    g[n-1][i]=0;
                }
            }
        
        void removeVertex(int v)
        {
            if(v>=n)
            {
                cout<<"\nVertex not present";
            }
            else
            {
                while(v<n)
                {
                    for(int i=0;i<n;i++)
                    {
                        // Shift the affected column index v to the left
                        g[i][v]=g[i][v+1];
                    }
                    for(int i=0;i<n;i++)
                    {
                        // Shift the affected row index v upwards
                        g[v][i]=g[v+1][i];
                    }
                    v++;
                }
                n--;    // Decrease the size by 1
            }
        }
};

int main()
{
    Graph graph(4);
    
    // Adding edges in the graph   
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    
    cout<<"\nElements of the graph after adding edges"<<endl;
    graph.displayAdjacencyMatrix();
    
    // Adding vertex to the graph
    graph.addVertex();
    
    cout<<"\nElements of the graph after adding vertex"<<endl;
    graph.displayAdjacencyMatrix();
    
    // Remove edge in the graph
    graph.removeEdge(0,2);
    
    cout<<"\nElements of the graph after removing edge"<<endl;
    graph.displayAdjacencyMatrix();
    
    // Remove vertex '2' from the graph
    graph.removeVertex(2);
    
    cout<<"\nElements of the graph after removing vertex 2"<<endl;
    graph.displayAdjacencyMatrix();
    return 0;
}
