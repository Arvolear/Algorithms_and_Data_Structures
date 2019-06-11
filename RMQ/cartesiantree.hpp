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
        int size;

        void dfs(vector < int > &order, vector < int > &depth, Node* node, int nodeDepth);
    public:
        Treap();

        Node* build(vector < Node* > &nodes);
        
        void linearize(vector < int > &order, vector < int > &depth, vector < int > &first);
        void print(Node* node, int number);

        Node*& getRoot();

        void clean(Node *node);
        ~Treap();
};
