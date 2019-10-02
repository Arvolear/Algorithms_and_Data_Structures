#include "red-black.hpp"

template < typename Key, typename Val >
RedBlack<Key, Val>::RedBlack()
{
    root = nullptr;
}

template < typename Key, typename Val >
typename RedBlack<Key, Val>::Node* RedBlack<Key, Val>::getParent(Node* node) const
{
    return node->parent;
}

template < typename Key, typename Val >
typename RedBlack<Key, Val>::Node* RedBlack<Key, Val>::getGrandParent(Node* node) const
{
    return node->parent ? node->parent->parent : nullptr;
}

template < typename Key, typename Val >
typename RedBlack<Key, Val>::Node* RedBlack<Key, Val>::getSibling(Node* node) const
{
    Node* parent = getParent(node);

    if (!parent)
    {
        return nullptr;
    }

    if (node == parent->left)
    {
        return parent->right;
    }
    else
    {
        return parent->left;
    }
}

template < typename Key, typename Val >
typename RedBlack<Key, Val>::Node* RedBlack<Key, Val>::getUncle(Node* node) const
{
    Node* parent = getParent(node);
    Node* grandParent = getGrandParent(node);

    if (!grandParent)
    {
        return nullptr;
    }

    return getSibling(parent);
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::rotateLeft(Node* node)
{
    Node* newNode = node->right;
    Node* parent = getParent(node);

    node->right = newNode->left;
    newNode->left = node;
    node->parent = newNode;

    if (node->right)
    {
        node->right->parent = node;
    }

    if (parent)
    {
        if (node == parent->left)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }

    newNode->parent = parent;
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::rotateRight(Node* node)
{
    Node* newNode = node->left;
    Node* parent = getParent(node);

    node->left = newNode->right;
    newNode->right = node;
    node->parent = newNode;

    if (node->left)
    {
        node->left->parent = node;
    }

    if (parent)
    {
        if (node == parent->right)
        {
            parent->right = newNode;
        }
        else
        {
            parent->left = newNode;
        }
    }

    newNode->parent = parent; 
}

template < typename Key, typename Val >
typename RedBlack<Key, Val>::Node* RedBlack<Key, Val>::insertRecursive(Node* root, Node* node)
{
    if (!root)
    {
        return node;
    }

    if (node->key < root->key)
    {
        root->left = insertRecursive(root->left, node);
        root->left->parent = root;
    }
    else if (node->key > root->key)
    {
        root->right = insertRecursive(root->right, node);
        root->right->parent = root;
    }

    return root;
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::repair(Node* node)
{
    if (!getParent(node))
    {
        repair1(node);
    }
    else if (getParent(node)->color == BLACK)
    {
        return;
    }
    else if (getUncle(node) && getUncle(node)->color == RED)
    {
        repair2(node);
    }
    else
    {
        repair3(node);
    }
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::repair1(Node* node)
{
    node->color = BLACK; 
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::repair2(Node* node)
{
    getParent(node)->color = BLACK;
    getUncle(node)->color = BLACK;
    getGrandParent(node)->color = RED;

    repair(getGrandParent(node));
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::repair3(Node* node)
{
    Node* parent = getParent(node);
    Node* grandParent = getGrandParent(node);

    if (parent == grandParent->left)
    {
        if (node == parent->right)
        {
            rotateLeft(parent);
            node = node->left;
        }

        rotateRight(getGrandParent(node));
    }
    else if (parent == grandParent->right)
    {
        if (node == parent->left)
        {
            rotateRight(parent);
            node = node->right;
        }

        rotateLeft(getGrandParent(node));
    }

    getParent(node)->color = BLACK;
    getGrandParent(node)->color = RED;
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::insert(const Key& key, const Val& val)
{
    Node* node = new Node(key, val);

    insertRecursive(root, node);

    repair(node);

    root = node;

    while (getParent(root))
    {
        root = getParent(root);
    }
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::remove(const Key& key)
{
}
        
template < typename Key, typename Val >
typename RedBlack<Key, Val>::Node* RedBlack<Key, Val>::findRecursive(Node* root, const Key& key)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        return findRecursive(root->left, key);
    }
    else if (key > root->key)
    {
        return findRecursive(root->right, key);
    }

    return nullptr;
}

template < typename Key, typename Val >
bool RedBlack<Key, Val>::find(const Key& key) const
{
    return findRecursive(root, key);
}

template < typename Key, typename Val >
Val& RedBlack<Key, Val>::operator[](const Key& key)
{
    Node* node = findRecursive(root, key);

    if (!node)
    {
        insert(key, Val());
    }

    return findRecursive(root, key)->val;
}
        
template < typename K, typename V >
ostream& operator<<(ostream& out, const RedBlack<K, V>& tree)
{
    queue < typename RedBlack<K, V>::Node* > q;

    q.push(tree.root);

    while (!q.empty())
    {
        typename RedBlack<K, V>::Node* node = q.front();
        q.pop();

        if (node)
        {
            out << "(" << node->key << ")" << node->val << " "; 

            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            out << "NULL ";
        }
    }

    out << endl;

    return out; 
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::clearRecursive(Node* root)
{
    if (!root)
    {
        return;
    }

    clearRecursive(root->left);
    clearRecursive(root->right);

    delete root;
}

template < typename Key, typename Val >
void RedBlack<Key, Val>::clear()
{
    clearRecursive(root);

    root = nullptr;
}

template < typename Key, typename Val >
RedBlack<Key, Val>::~RedBlack()
{
    clear(); 
}
