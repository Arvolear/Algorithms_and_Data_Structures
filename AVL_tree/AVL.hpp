#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

struct Node
{
    int key;
    int height;
 
    weak_ptr < Node > parent;
    shared_ptr < Node > left;
    shared_ptr < Node > right;

    Node(int k)
    { 
        key = k; height = 1; parent = left = right = nullptr; 
    }
};

class AVL
{
    private:
        shared_ptr < Node > root;
        int size;

        int getHeight(shared_ptr < Node >& node);
        int getBalanceFactor(shared_ptr < Node >& node);
        void fixHeight(shared_ptr < Node >& node);

        shared_ptr < Node > rotateLeft(shared_ptr < Node >& base);
        shared_ptr < Node > rotateRight(shared_ptr < Node >& base);
        shared_ptr < Node > fixBalance(shared_ptr < Node >& base);

        shared_ptr < Node > findMin(shared_ptr < Node >& node);
        shared_ptr < Node > removeMin(shared_ptr < Node >& node);

    public:
        AVL();

        shared_ptr < Node > insert(shared_ptr < Node >& node, int k);
        shared_ptr < Node > find(shared_ptr < Node >& node, int k);
        shared_ptr < Node > remove(shared_ptr < Node >& node, int k);
        
        void print(shared_ptr < Node >& node);

        shared_ptr < Node > getRoot();
        int getSize();

        ~AVL();
};
