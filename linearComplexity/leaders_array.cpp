/*  Solve the leaders in an array program in linear complexity
    Print all the leaders in an array. A leader is an element
    if all the elements to the right of that element are smaller  */

/*  PSEUDOCODE -
    1. Insert the last element
    2. Store the maximum value until now. 
    3. If the current value is larger than the max value it's a leader (convert the max to the current leader)
    3. else move to the next element
*/

#include <vector>
#include <iostream>

using namespace std;

//  computeLeaders
vector<int> computeLeaders(vector<int>& v)
{
  size_t size = v.size();
  vector<int> leaders;
  if(size == 0)
    return leaders;
  leaders.push_back(v[size-1]);
  int max_val = v[size-1];
  for(int i = size-2;i>=0;i--)
  {
    if(i==size-1)
    {
      leaders.push_back(v[i]);
      max_val = v[i];
    }
    else
    {
      if(v[i] > max_val)
      {
        leaders.push_back(v[i]);
        max_val = v[i];
      }
    }
  }
  return leaders;
}

void print_vector(vector<int>& nums)
{
  for(int num:nums)
    cout << num << " ";
  cout << "\n";
}

int main()
{
  vector<int> v1 = {10, 9, 8, 7, 6, 5};
  vector<int> v2 = {1, 4, 12, 5, 6, 2};
  //  
  auto v1_leaders = computeLeaders(v1);
  print_vector(v1_leaders);
  auto v2_leaders = computeLeaders(v2);
  print_vector(v2_leaders);
  
  return 0;
}
