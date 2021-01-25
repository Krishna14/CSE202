#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//  shortest_cell_path() is a function used to compute the shortest path between points
//  sr, sc and tr, tc
int shortest_cell_path_BFS(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
    //  Approach 1: DFS
    //  Approach 2: BFS
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while(!q.empty())
    {
        for(int i=0;i<q.size();i++)
        {
            auto top = q.front();
            q.pop();
            vector<pair<int,int>> possible_movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for(auto movement : possible_movements)
            {
                
            }
        }
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}};
    
}
