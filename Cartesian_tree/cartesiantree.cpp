#include "cartesiantree.hpp"

Treap::Treap()
{
    root = nullptr;
}

Node* Treap::merge(Node* leftTree, Node* rightTree)
{
    if (leftTree == nullptr)
    {
        return rightTree;
    }

    if (rightTree == nullptr)
    {
        return leftTree;
    }

    if (leftTree->prior <= rightTree->prior) // left is closer to root
    {
        /* left tree of left is fine */ 
        leftTree->right = merge(leftTree->right, rightTree);
        leftTree->right->parent = leftTree;
        
        return leftTree;
    }
    else
    {
        /* right tree of right is fine */ 
        rightTree->left = merge(leftTree, rightTree->left);
        rightTree->left->parent = rightTree;
        
        return rightTree;
    }
}

pair < Node*, Node* > Treap::split(Node* tree, int key)
{
    if (tree == nullptr)
    {
        return {nullptr, nullptr};
    }

    if (key > tree->key) // going right and returning left
    {
        pair < Node*, Node* > trees = split(tree->right, key);

        /* because we have returned from right tree, 
         * right node of current tree has to be less than
         * right tree */
        tree->right = trees.first;
        tree->right->parent = tree;

        /* so current tree is less than right tree */
        return {tree, trees.second}; 
    }
    else
    {
        pair < Node*, Node* > trees = split(tree->left, key);
        
        /* because we have returned from left tree, 
         * left node of current tree has to be grater than
         * left tree */
        tree->left = trees.second;
        tree->left->parent = tree;

        /* so current tree is grater than left tree */
        return {trees.first, tree}; 
    }
}

Node* Treap::build(vector < Node* > &nodes)
{
    Node* last = nodes[0];

    for (int i = 1; i < nodes.size(); i++)
    {
        /* if new node prior >= last node prior 
         * make new node right child of last node */
        if (nodes[i]->prior >= last->prior)
        {
            last->right = new Node(nodes[i]->key, nodes[i]->prior, last, nullptr, nullptr);

            /* update last */
            last = last->right;
        }
        else
        {
            Node* current = last;

            while (current->parent != nullptr && 
                   nodes[i]->prior < current->prior)
            {
                current = current->parent;
            }

            /* changing root spot */
            if (nodes[i]->prior < current->prior)
            {
                last = new Node(nodes[i]->key, nodes[i]->prior, nullptr, current, nullptr);
                
                current->parent = last;
            }
            else
            {
                current->right = new Node(nodes[i]->key, nodes[i]->prior, current, current->right, nullptr);

                current->right->left->parent = current->right;
                last = current->right;
            }
        }
    }

    while (last->parent != nullptr)
    {
        last = last->parent;
    }

    root = last;
    return root;
}

Node* Treap::insert(Node* tree, Node* node)
{
    if (tree == nullptr)
    {
        if (root == nullptr)
        {
            root = node;
        }

        return node;   
    }

    if (node->prior >= tree->prior) // place is found
    {
        /* spliting tree on current node */
        pair < Node*, Node* > trees = split(tree, node->key);
        
        /* sign node to be a parent for left and right trees */
        node->left = trees.first;
        node->right = trees.second;

        root = node;
        return node;
    }
    
    if (node->key >= tree->key) // going right
    {
        tree->right = insert(tree->right, node);
        tree->right->parent = tree;
    }
    else
    {
        tree->left = insert(tree->left, node);
        tree->left->parent = tree;
    }

    root = tree;
    root->parent = nullptr;
}

Node* Treap::remove(Node*& tree, int key)
{
    if (tree == nullptr) // node wasn't found
    {
        return tree;
    }

    if (tree->key == key) // node is found
    {
        Node* treeLeft = tree->left;
        Node* treeRight = tree->right;

        delete tree;
        tree = nullptr;

        Node* node = merge(treeLeft, treeRight); // merging sons of the node

        if (root == nullptr)
        {
            root = node;
        }

        return node;
    }

    if (key >= tree->key) // going right 
    {
        tree->right = remove(tree->right, key);
        tree->right->parent = tree;
    }
    else
    {
        tree->left = remove(tree->left, key);
        tree->left->parent = tree;
    }

    root = tree;
    root->parent = nullptr;
    return tree;
}

/*Node* Treap::unite(Node* treeLeft, Node* treeRight)
{
    // TODO: something with root in the end 



    if (treeLeft == nullptr)
    {
        return treeRight;
    }
    
    if (treeRight == nullptr)
    {
        return treeLeft;
    }

    /* here we are choosing the root of the tree.
     * Making left to be the one *
    if (treeLeft->prior < treeRight->prior) 
    {
        swap(treeLeft, treeRight);
    }

    /* spliting right tree with root key of left tree *
    pair < Node*, Node* > trees = split(treeRight, treeLeft->key); 
    /* those are left and right trees of right tree *

    Node* result = treeLeft;

    result->right = unite(treeLeft->right, trees.second);
    result->right->parent = result;
    
    result->left = unite(treeLeft->left, trees.first);
    result->left->parent = result;

    return result;
}*/

bool Treap::search(Node* tree, Node* node)
{
    if (tree == nullptr) // key was't found
    {
        return false;
    }

    if (tree->key == node->key) // key is found
    {
        return true;
    }

    if (node->key >= tree->key) // going right
    {
        return search(tree->right, node);
    }
    else
    {
        return search(tree->right, node);
    }
}

void Treap::print(Node* node, int number)
{
    if (root == nullptr)
    {
        cout << "The tree is empty!\n";
        return;
    }

    if (node == nullptr)
    {
        return;
    }

    /* recursion */
    print(node->left, number + 1);

    /* print layer */
    if (!number)
    {
        cout << "root\n";
    }

    /* print info */
    cout << "key: " << node->key << ' ';
    cout << "Prior: " << node->prior << endl;
    
    /* print parent */
    if (node->parent != nullptr)
    {
        cout << "Parent: " << node->parent->prior << endl;
    }
    else
    {
        cout << "Parent: null\n";
    }

    /* print left child */
    if (node->left != nullptr)
    {
        cout << "Left: " << node->left->prior << ' ';
    }
    else
    {
        cout << "Left: null ";
    }

    /* print right child */
    if (node->right != nullptr)
    {
        cout << "Right: " << node->right->prior << endl << endl;
    }
    else
    {
        cout << "right: null\n\n";
    }

    /* recursion */
    print(node->right, number + 1);
}

Node*& Treap::getRoot()
{
    return root;
}

Treap::~Treap(){}
