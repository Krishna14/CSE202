#include <iostream>
#include <vector>

using namespace std;

struct Node 
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    //  For sparse graphs, binary heap method is good
    Node(int x) : val(x) {}
};

class binaryHeap
{
    private:
        Node* root = nullptr;
    public:
        //  Heapify is used to convert the given datastructure to a min heap
        void heapifyUp();
        void 
    

};

//  
int main()
{

}
