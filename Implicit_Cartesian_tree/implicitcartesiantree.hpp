#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <iomanip>
#include <string>

using namespace std;

struct Node
{
    int children;

    int prior;

    Node* parent;
    Node* left;
    Node* right;

    Node(int p)
    {
        children = 1;
        prior = p;

        parent = left = right = nullptr;
    }
};

class ImpTreap
{
    private:
        Node* root;

        Node* merge(Node* leftTree, Node* rightTree);
        pair < Node*, Node* > split(Node* tree, int key);
        void updateChildren(Node* tree);

    public:
        ImpTreap();

        Node* insert(Node* node, int position);
        Node* remove(int key);

        void print(Node* node, int number = 0, int implicitKey = 0);

        Node*& getRoot();

        ~ImpTreap();
};
