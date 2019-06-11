#include "implicitcartesiantree.hpp"

ImpTreap::ImpTreap()
{
    root = nullptr;
}

Node* ImpTreap::merge(Node* leftTree, Node* rightTree)
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
        updateChildren(leftTree);
        
        return leftTree;
    }
    else
    {
        /* right tree of right is fine */ 
        rightTree->left = merge(leftTree, rightTree->left);
        updateChildren(rightTree);
        
        return rightTree;
    }
}

pair < Node*, Node* > ImpTreap::split(Node* tree, int position)
{
    if (tree == nullptr)
    {
        return {nullptr, nullptr};
    }

    if (tree->left == nullptr)
    {
        if (position >= 1)
        {
            pair < Node*, Node* > trees = \
            split(tree->right, position - 1);

            /* because we have returned from right tree, 
             * right node of current tree has to be less than
             * right tree */
            tree->right = trees.first;
            updateChildren(tree);

            /* so current tree is less than right tree */
            return {tree, trees.second}; 
        }
        else
        {
            return {nullptr, tree};
        }
    }
    /* leaving root in the left, position is more to the right */
    else if (position > tree->left->children) // going right and returning to the  left
    {
        pair < Node*, Node* > trees = \
        split(tree->right, position - (tree->left->children + 1));

        /* because we have returned from right tree, 
         * right node of current tree has to be less than
         * right tree */
        tree->right = trees.first;
        updateChildren(tree);

        /* so current tree is less than right tree */
        return {tree, trees.second}; 
    }
    else
    {
        pair < Node*, Node* > trees = split(tree->left, position);

        /* because we have returned from left tree, 
         * left node of current tree has to be grater than
         * left tree */
        tree->left = trees.second;
        updateChildren(tree);

        /* so current tree is grater than left tree */
        return {trees.first, tree}; 
    }
}

void ImpTreap::updateChildren(Node* tree)
{
    if (tree == nullptr)
    {
        return;
    }

    int amount = 1;

    if (tree->left != nullptr)
    {
        tree->left->parent = tree;
        amount += tree->left->children;
    }

    if (tree->right != nullptr)
    {
        tree->right->parent = tree;
        amount += tree->right->children;
    }

    tree->children = amount;
}

Node* ImpTreap::insert(Node* node, int position)
{
    if (root == nullptr)
    {
        root = node;
        return root;   
    }

    /* spliting tree on the given position (index), 
     * root will be in the right one */
    pair < Node*, Node* > trees = split(root, position);

    /* merging left tree with new node */
    Node* tmp = merge(trees.first, node);
    /* merging right tree with new left tree */
    root = merge(tmp, trees.second);

    root->parent = nullptr;

    return root;
}

Node* ImpTreap::remove(int position)
{
    if (root == nullptr) // node wasn't found
    {
        cout << "The tree is empty!\n";
        return root;
    }

    /* spliting given tree with given position,
     * so the position to be in the right tree */
    pair < Node*, Node* > trees1 = split(root, position);

    /* spliting right tree so the position to be left alone
     * in the new left tree */
    pair < Node*, Node* > trees2 = split(trees1.second, 1);

    delete trees2.first;

    /* merging first left tree with second right tree */
    root = merge(trees1.first, trees2.second);

    root->parent = nullptr;

    return root;
}

void ImpTreap::print(Node* node, int number, int implicitKey)
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

    print(node->left, number + 1, implicitKey);

    /* print layer */
    if (!number)
    {
        cout << "root\n";
    }

    /* print info */
    if (node->left != nullptr)
    {
        cout << "Pos: " << node->left->children + implicitKey << ' ';
    }
    else
    {
        cout << "Pos: " << implicitKey << ' ';
    }

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
    if (node->left != nullptr)
    {
        print(node->right, number + 1, node->left->children + implicitKey + 1);
    }
    else
    {
        print(node->right, number + 1, implicitKey + 1);
    }
}

Node*& ImpTreap::getRoot()
{
    return root;
}

ImpTreap::~ImpTreap(){}
