#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

void helper(Node* root, int num, int& largestSmaller)
{
    if(root == nullptr)
        return;
    
    if(root->val < num)
    {
        largestSmaller = root->val;
        helper(root->right, num, largestSmaller);
    }
    else
    {
        helper(root->left, num, largestSmaller);
    }
}

int findLargestSmallerKey(Node* root, int num)
{
    int largestSmaller = -1;
    helper(root, num, largestSmaller); 
    return largestSmaller;  
}

int main()
{
    Node* root = new Node(20);
    root->left = new Node(13);
    root->right = new Node(25);
    root->left->left = new Node(11);
    root->left->right = new Node(17);
    
    int val = findLargestSmallerKey(root, 14);
    cout << " Largest smaller key = " << val << "\n";

    return 0;
}
