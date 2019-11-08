#include "AVL.hpp"

AVL::AVL()
{
    root = nullptr;
    size = 0;
}

int AVL::getHeight(shared_ptr < Node >& node)
{
    return node ? node->height : 0;
}

int AVL::getBalanceFactor(shared_ptr < Node >& node)
{
    return getHeight(node->right) - getHeight(node->left);
}

void AVL::fixHeight(shared_ptr < Node >& node)
{
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

shared_ptr < Node > AVL::rotateLeft(shared_ptr < Node >& base)
{
    shared_ptr < Node > goesUp = base->right;
    shared_ptr < Node > goesToBase = goesUp->left;

    base->right = goesToBase;
    goesUp->left = base;

    base->parent = goesUp;

    if (goesToBase != nullptr)
    {
        goesToBase->parent = base;
    }

    fixHeight(base);
    fixHeight(goesUp);

    if (base == root)
    {
        root = goesUp;

        if (root != nullptr)
        {
            root->parent.reset();
        }
    }

    return goesUp;
}

shared_ptr < Node > AVL::rotateRight(shared_ptr < Node >& base)
{
    shared_ptr < Node > goesUp = base->left;
    shared_ptr < Node > goesToBase = goesUp->right;

    base->left = goesToBase;
    goesUp->right = base;
    
    base->parent = goesUp;

    if (goesToBase != nullptr)
    {
        goesToBase->parent = base;
    }

    fixHeight(base);
    fixHeight(goesUp);
    
    if (base == root)
    {
        root = goesUp;

        if (root != nullptr)
        {
            root->parent.reset();
        }
    }

    return goesUp;
}

shared_ptr < Node > AVL::fixBalance(shared_ptr < Node >& base)
{
    fixHeight(base);

    /* need to perform left turn around base */
    if (getBalanceFactor(base) > 1) // right is greater than left
    {
        if (getBalanceFactor(base->right) < 0) // left is grater than right
        {
            base->right = rotateRight(base->right);
        }

        return rotateLeft(base);
    }
    /* right turn instead */
    else if (getBalanceFactor(base) < -1)
    {
        if (getBalanceFactor(base->left) > 0) // right is grater than left
        {
            base->left = rotateLeft(base->left);
        }

        return rotateRight(base);
    }

    return base;
}

shared_ptr < Node > AVL::insert(shared_ptr < Node >& node, int k)
{
    if (root == nullptr)
    {
        size++;
        root = shared_ptr < Node > (new Node(k));
        root->parent.reset();
        return nullptr;
    }

    if (node == nullptr)
    {
        size++;
        return shared_ptr < Node > (new Node(k));
    }

    if (k < node->key) // value is less than current node value
    {
        node->left = insert(node->left, k);
        
        if (node->left != nullptr)
        {
            node->left->parent = node;
        }
    }
    else if (k >= node->key) // value is greater than current node value
    {
        node->right = insert(node->right, k);
        
        if (node->right != nullptr)
        {
            node->right->parent = node; 
        }
    }

    return fixBalance(node);
}
        
shared_ptr < Node > AVL::find(shared_ptr < Node >& node, int k)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (k > node->key)
    {
        return find(node->right, k);
    }
    else if (k == node->key)
    {
        return node;
    }
    else
    {
        return find(node->left, k);
    }
}

shared_ptr < Node > AVL::findMin(shared_ptr < Node >& node)
{
    return node->left ? findMin(node->left) : node;
}

shared_ptr < Node > AVL::removeMin(shared_ptr < Node >& node)
{
    if (node->left == nullptr) // if left node is absent 
    {
        return node->right; // making upper left node this right node
    }

    node->left = removeMin(node->left); 

    return fixBalance(node); // other nodes still point to left ones
}

shared_ptr < Node > AVL::remove(shared_ptr < Node >& node, int k)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (k == root->key)
    {
        size--;
        root = root->right;

        if (root != nullptr)
        {
            root->parent.reset();
        }

        return nullptr;
    }

    if (k < node->key)
    {
        node->left = remove(node->left, k);
        
        if (node->left != nullptr)
        {
            node->left->parent = node; 
        }
    }
    else if (k > node->key)
    {
        node->right = remove(node->right, k);

        if (node->right != nullptr)
        {
            node->right->parent = node; 
        }
    }
    else
    {
        size--;
        shared_ptr < Node > left = node->left;
        shared_ptr < Node > right = node->right;

        if (right == nullptr) // if !right - left is maximum
        {
            return left;
        }

        shared_ptr < Node > min = findMin(right); // searching for node wich value is maximally close to the deleted one
        min->left = left; // left node receives left tree
        min->right = removeMin(right); // right node receives right tree without min node

        return fixBalance(min); // upper node gets min node as a child
    }

    return fixBalance(node); // other nodes are left untouched
}
        
void AVL::print(shared_ptr < Node >& node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << "\t\"" << node->key << "\": {\n";

    cout << "\t\t\"balance factor\": " << getBalanceFactor(node) << ",\n";
    cout << "\t\t\"height\": " << node->height << ",\n";
    
    if (node->parent.lock() != nullptr)
    {
        cout << "\t\t\"parent\": " << node->parent.lock()->key << ",\n";
    }

    if (node->left != nullptr)
    {
        cout << "\t\t\"left\": " << node->left->key << ",\n";
    }
    
    if (node->right != nullptr)
    {
        cout << "\t\t\"right\": " << node->right->key << ",\n";
    }
    
    if (node == root)
    {
        cout << "\t\t\"root\": " << "true" << ",\n";
    }

    cout << "\t},\n";
   
    print(node->left);
    print(node->right);
}

shared_ptr < Node > AVL::getRoot()
{
    return root;
}

int AVL::getSize()
{
    return size;
}

AVL::~AVL(){}
