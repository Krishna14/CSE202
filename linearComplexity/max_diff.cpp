/*  Compute the max difference of A[i] - A[j] over all choices
    of indices such that j > i  */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define A_FATAL(a, b) { if(!(a)) { cout << b << endl; exit(0); } }

int maxDiff(vector<int>& nums)
{
  //  Start from the (size - 2) index
  //  Store the min_val as the right most value
  //  Also compute the difference between a[size-2] - a[size-1]
  //  if (current_difference > max_difference)
  //  {
  //    max_difference = current_difference;
  //  }
  //  EXAMPLE : 1 4 5 12 6 9 12 3 9
  size_t size = nums.size();
  if(size == 0)
    return 0;
  int min_val = nums[size-1];
  int max_difference = INT_MIN;
  for(int i=size-2;i>=0;i--)
  {
    if(nums[i] - min_val > max_difference)
      max_difference = (nums[i] - min_val);
    //  This needs to be done after the previous check 
    //  because
    if(nums[i] < min_val)
      min_val = nums[i];
  }
  return max_difference;
}

int main()
{
  vector<int> v1 = {1, 4, 5, 12, 6, 9, 12, 3, 9};
  vector<int> v2 = {5, 12, 10, 9};
  int max_diff_1 = maxDiff(v1);
  A_FATAL(max_diff_1 == 9, "Wrong answer");
  int max_diff_2 = maxDiff(v2);
  A_FATAL(max_diff_2 == 3, "Wrong answer");

  return 0;
}

