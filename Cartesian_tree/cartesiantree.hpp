#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

struct Node
{
    int key, prior;

    Node* parent;
    Node* left;
    Node* right;

    Node(int k, int p)
    {
        key = k;
        prior = p;

        parent = left = right = nullptr;
    }
    
    Node(int k, int p, Node* P, Node* L, Node* R)
    {
        key = k;
        prior = p;

        parent = P;
        left = L;
        right = R;
    }
};

class Treap
{
    private:
        Node* root;

        Node* merge(Node* leftTree, Node* rightTree);
        pair < Node*, Node* > split(Node* tree, int key);

    public:
        Treap();

        Node* build(vector < Node* > &nodes);
        Node* insert(Node* tree, Node* node);
        Node* remove(Node*& tree, int key);
        //Node* unite(Node* treeLeft, Node* treeRight);

        bool search(Node* tree, Node* node);

        void print(Node* node, int number);

        Node*& getRoot();

        ~Treap();
};
