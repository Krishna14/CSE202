#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

//  Vertex is the structure that's used here
struct Vertex
{
    int numJugs = 0;
    vector<int> jugVolumes;
    Vertex(int a, vector<int>& vols) : numJugs(a)
    {
        jugVolumes.resize(a);
        jugVolumes = vols;
    }
    void printVertex()
    {
        cout << "The volumes in each of the jugs are \n";
        for(int vol : jugVolumes)
        {
            cout << vol << " ";
        }
        cout << "\n";
    }
};

//  print_vector() is used to compute the set of elements in a vector
void print_vector(vector<int>& nums)
{
    for(int ele : nums)
        cout << ele << " ";
    cout << "\n";
}

void print2Dvector(vector<vector<int>>& nums)
{
    for(auto vec : nums)
    {
        cout << "{ ";
        for(int ele : vec)
            cout << ele << " ";
        cout << "}, ";
    }
}

bool compare(vector<int>& current_state, vector<int>& target_state)
{
    size_t size = current_state.size();
    for(int i=0;i<size;i++)
    {
        if(current_state[i] != target_state[i])
            return false;
    }
    return true;
}

bool compute_adjacent_nodes(vector<int>& init_state,
    vector<int>& capacities, unordered_map<string, vector<int>>& vertices_map, 
    vector<int>& target_state, bool debug_mode = false)
{
    vector<vector<int>> result;
    queue<vector<int>> q;
    q.push(init_state);
    bool targetReached = false;
    while(!q.empty())
    {
        vector<int> current_state = q.front();
        q.pop();
        if(compare(current_state, target_state))
        {
            cout << "Reached target state ";
            print_vector(target_state);
            cout << "\n";
            targetReached = true;
            break;
        }
        for(int i=0;i<current_state.size();i++)
        {
            for(int j=0;j<current_state.size();j++)
            {
                if(i != j)
                {
                    int jug_i = current_state[i];
                    //  Transferring from i to j
                    int jug_j = current_state[j];
                    //  What is the maximum that could be poured there?
                    int possible_to_pour = (capacities[j] - jug_j);
                    int amount_to_pour;
                    //  Fill the entire jug
                    if(jug_i < possible_to_pour)
                        amount_to_pour = jug_i;
                    else
                        //  Compute the amount to be poured and pour it in the jug
                        amount_to_pour = possible_to_pour;
                    //  Remove the jug_i only if there's something to take out of it
                    if(jug_i != 0)
                    {
                        vector<int> new_state = current_state;
                        new_state[i] = (jug_i - amount_to_pour);
                        new_state[j] += amount_to_pour;
                        string newStateKey = to_string(new_state[0]) + to_string(new_state[1]) + to_string(new_state[2]);
                        if(vertices_map.find(newStateKey) == vertices_map.end())
                        {
                            vertices_map[newStateKey] = new_state;
                            q.push(new_state);
                            if(debug_mode)
                                cout << " New state = "; print_vector(new_state); cout << " added to the queue \n";
                            result.push_back(new_state);
                        }
                    }
                }
            }
        }
    }

    if(debug_mode)
    {
        cout << "For the original vertex = ";
        print_vector(init_state);
        cout << ", the possible combinations of vectors are \n";
        print2Dvector(result);
        cout << "\n";
    }
    return targetReached;
}

int main()
{
    int numJugs = 3;
    vector<int> jugVolumes = {200, 400, 700};
    vector<int> initState = {200, 400, 0};
    //  
    vector<int> targetState_1 = {200, 100, 300};
    vector<int> targetState_2 = {200, 200, 200};
    Vertex a = Vertex(3, initState);
    
    //  Create an unordered_map to store the previous vertices that have been visited
    unordered_map<string, vector<int>> vertices_map;
    string initStateKey = to_string(initState[0]) + to_string(initState[1]) + to_string(initState[2]);
    //  Add the initial state to the "vertices_map"
    vertices_map[initStateKey] = initState;
    
    unordered_map<string, bool> visited_map;
    bool found_1 = compute_adjacent_nodes(initState, jugVolumes, vertices_map, targetState_1, true);

    //  found_1
    if(found_1)
    {
        cout << "Target = "; 
        print_vector(targetState_1); 
        cout << " reached from "; 
        print_vector(initState); cout << "\n";
    }
    else
    {
        cout << "Target = "; 
        print_vector(targetState_1); 
        cout << " can't be reached from "; 
        print_vector(initState); cout << "\n";
    }
    
    vertices_map.clear();   //  This is used to clear the contents of the map
    vertices_map[initStateKey] = initState;
    bool found_2 = compute_adjacent_nodes(initState, jugVolumes, vertices_map, targetState_2, true);
    if(found_2)
    {
        cout << "Target = ";
        print_vector(targetState_2); 
        cout << " reached from "; 
        print_vector(initState); cout << "\n";
    }
    else
    {
        cout << "Target = ";
        print_vector(targetState_1); 
        cout << " can't be reached from "; 
        print_vector(initState); cout << "\n";
    }
    
    return 0;
}
