#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

//  Edge
struct Edge
{
    int src = 0;
    int dest = 0;
    int weight = 0;
    Edge(int a, int b) : src(a), dest(b) {}
    Edge(int a, int b, int c) : src(a), dest(b), weight(c) {}
};

//  Graph
class Graph
{
    private:
        int V = 0;              //  Denotes the number of vertices
        vector<list<int>> adj;  //  Denotes the adjacency list of the graph
        vector<list<pair<int, int>>> weighted_adj;   //  Adj list for the weighted graph
        vector<vector<int>> adj_matrix; //  Adjacency matrix representation for the graph
        bool directed = false;  //  Is this really a "directed" graph?
        bool weighted = false;  //  Is this really a "weighted" graph?
    public:
        //  Graph()
        Graph(int vert) : V(vert) {}
        //  Graph()
        Graph(int vert, vector<Edge>& edges, bool _weighted_, bool _directed_)
        {
            V = vert;
            adj.resize(vert + 1);
            directed = _directed_, weighted = _weighted_;
            adj_matrix.resize(vert + 1);
            for(int i=0;i<=V;i++)
                adj_matrix[i].resize(vert + 1, 0);
            
            if(!weighted)
            {
                for(auto it=edges.begin(); it != edges.end(); it++)
                {
                    //  Compute whether there's a path that exists between "src" and "dest" nodes?
                    adj[it->src].push_back(it->dest);
                    adj_matrix[it->src][it->dest] = 1;
                    //  If the graph's not directed
                    if(!directed)
                    {
                        adj[it->dest].push_back(it->src);
                        adj_matrix[it->src][it->dest] = 1;
                    }
                }
            }
            else
            {
                for(auto it=edges.begin(); it != edges.end(); it++)
                {
                    weighted_adj[it->src].push_back({it->dest, it->weight});
                    //  If the graph's not directed
                    if(!directed)
                        weighted_adj[it->dest].push_back({it->src, it->weight});
                }
            }
        }
        //  printUnweightedAdj() is used to print the contents of the unweighted adjacency list
        void printUnweightedAdj()
        {
            for(int i=0;i<=V;i++)
            {
                cout << "SRC: " << i << "->";
                for(auto it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << " ";
                }
                cout << "\n";
            }
        }
        //  printWeightedAdj() is used to print the contents of the weighted adjacency list
        void printWeightedAdj()
        {
            for(int i=0;i<=V;i++)
            {
                cout << "SRC: " << i << "->";
                for(auto it = weighted_adj[i].begin(); it != weighted_adj[i].end(); it++)
                {
                    cout << "(" << it->first << ", " << it->second << ") ";
                }
                cout << "\n";
            }
        }
        /*  Prints the contents of the adjacency std::list<T>   */
        void print_adj()
        {
            if(!weighted)
                printUnweightedAdj();
            else
                printWeightedAdj();
        }
        //  findCycles()
        void findCycles(int src, int parent, vector<int>& Color,
            vector<int>& mark, vector<int>& par, int& cycleNumber, vector<vector<int>>& cycles);
        //  detect_triangles_adjlist()
        bool detect_triangles_adjlist(int src)
        {
            vector<bool> visited(V + 1, false);
            vector<int> ancestors;  //  Assume that the nodes are integers
            return false;
        }
        int detect_triangles_adjmatrix();
        int singleSourceShortestPath(int src, int dest);
};

#endif  /* Graph.h */
