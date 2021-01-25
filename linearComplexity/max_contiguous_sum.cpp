/*  Use a divide and conquer approach to write an efficient recursive algorithm
    that finds the maximum sum in any contiguous sublist of a given list of n 
    (+ve or -ve values). Analyze the algorithm and show the results in order notation */
#include <vector>
#include <iostream>
#include <cassert>
#include <climits>

using namespace std;

#define A_FATAL(a, b) { if(!(a)) { cout << b << endl; } }

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maxCrossingSum(vector<int>& nums, int mid, int left, int right)
{
    //  Include elements on the left
    int sum = 0;
    int leftSum = INT_MIN;
    for(int i=mid;i>=left;i--)
    {
        sum += nums[i];
        if(sum > leftSum)
        {
            leftSum = sum;
        }
    }
    
    //  Include elements on the right
    sum = 0;
    int rightSum = INT_MIN;
    for(int i=mid+1;i<=right;i++)
    {
        sum += nums[i];
        if(sum > rightSum)
            rightSum = sum;
    }

    cout << "maxCrossingSum called with left = " << left
        <<  ", right = " << right << ", mid = " << mid << "\n";

    return (leftSum + rightSum, leftSum, rightSum);
}

int maxSubArraySum(vector<int>& nums, int left, int right)
{
    cout << "maxSubArraySum called with left = " << left
        << ", right = " << right << "\n";
    //  What if left "equals" right?
    if(left == right)
        return nums[left];
    //  
    int mid = left + (right - left)/2;
    int leftSum = maxSubArraySum(nums, left, mid);
    int rightSum = maxSubArraySum(nums, mid+1, right);
    //  
    cout << "At (left, right) = " << left << ", " << right
        << ", leftSum = " << leftSum << ", rightSum = " << rightSum 
        << ", crossing sum = " << leftSum + rightSum << "\n";

    return max(leftSum, rightSum, leftSum + rightSum);
}

void print_vector(vector<int>& nums)
{
    for(int num : nums)
    {
        cout << num << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> nums = {6, 3, -4, 5, 7};
    cout << "The original vector looks like \n";
    print_vector(nums);
    int maxsum = maxSubArraySum(nums, 0, nums.size() - 1);
    A_FATAL(maxsum == 17, "The value of maxsum = " << maxsum << endl);

    return 0;
}
