#include <iostream>
#include "graph.h"

using namespace std;

enum color
{
    white = 0,
    gray = 1,
    black = 2
};

void 
Graph::findCycles(int src, int parent, vector<int>& Color, 
    vector<int>& mark, vector<int>& par, int& cycleNumber, vector<vector<int>>& cycles)
{
    //  If the node has already been processed
    if(Color[src] == 2)
        return;
    
    //  If the node has been visited, but children are still being processed
    if(Color[src] == 1)
    {
        cycleNumber++;
        int current = parent;
        mark[current] = cycleNumber;
        
        while(current != src)
        {
            current = par[current];
            mark[current] = cycleNumber;
        }
        return;
    }
    //  Storing the ancestors here
    par[src] = parent;
    
    //  This is a partially visited graph
    Color[src] = 1;
    if(!weighted)
    {
        for(int v : adj[src])
        {
            if(v == par[src])
                continue;
            findCycles(v, src, Color, mark, par, cycleNumber, cycles);
        }
    }
    else
    {
        for(auto v : weighted_adj[src])
        {
            if(v.first == par[src])
                continue;
            findCycles(v.first, src, Color, mark, par, cycleNumber, cycles);
        }
    }
    //  Completely visited
    Color[src] = 2;
}

int
Graph::detect_triangles_adjmatrix()
{
    int numTriangles = 0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                if(adj_matrix[i][j] && adj_matrix[j][k] 
                        && adj_matrix[k][j])
                    numTriangles += 1;
            }
        }
    }

    numTriangles = (directed) ? numTriangles/3 : numTriangles/6;
    return numTriangles;
}


//  main() function is used here
int main()
{
    //  Edge is a collection of (src, dest) pairs in the graph
    vector<Edge> edges_1;
    edges_1.push_back(Edge(1, 2));
    edges_1.push_back(Edge(2, 3));
    edges_1.push_back(Edge(3, 1));

    //  
    vector<Edge> edges_2;
    edges_2.push_back(Edge(1, 2));
    edges_2.push_back(Edge(1, 3));
    edges_2.push_back(Edge(1, 4));
    edges_2.push_back(Edge(4, 5));
    edges_2.push_back(Edge(7, 8));
    edges_2.push_back(Edge(4, 6));
    edges_2.push_back(Edge(5, 8));
    edges_2.push_back(Edge(6, 8));
    edges_2.push_back(Edge(3, 7));
    edges_2.push_back(Edge(6, 7));

    int vertices_1 = 3, vertices_2 = 8;
    //  That is commonly used to compute the actual edge between 2 and 3
    Graph g1 = Graph(vertices_1, edges_1, false, false);
    cout << "adjacency list of the first graph \n";
    g1.print_adj();
    int value_1 = g1.detect_triangles_adjmatrix();
    cout << "Detected triangles for G1 = " << value_1 << "\n";
    //  That is commonly used to compute the actual edge between 1 and 2
    Graph g2 = Graph(vertices_2, edges_2, false, false);
    cout << "adjacency list of the second graph \n";
    g2.print_adj();
    int value_2 = g2.detect_triangles_adjmatrix();
    cout << "Detected triangles for G2 = " << value_2 << "\n";
    //  
    return 0;
}
