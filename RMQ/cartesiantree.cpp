#include "cartesiantree.hpp"

Treap::Treap()
{
    root = nullptr;
    size = 0;
}

void Treap::dfs(vector < int > &order, vector < int > &depth, Node* node, int nodeDepth)
{
    if (node == nullptr)
    {
        return;
    }

    order.push_back(node->key);
    depth.push_back(nodeDepth);

    if (node->left != nullptr)
    {
        dfs(order, depth, node->left, nodeDepth + 1);

        order.push_back(node->key);
        depth.push_back(nodeDepth);
    }

    if (node->right != nullptr)
    {
        dfs(order, depth, node->right, nodeDepth + 1);

        order.push_back(node->key);
        depth.push_back(nodeDepth);
    }
}

Node* Treap::build(vector < Node* > &nodes)
{
    size = nodes.size();
    Node* last = nodes[0];

    for (size_t i = 1; i < nodes.size(); i++)
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

void Treap::linearize(vector < int > &order, vector < int > &depth, vector < int > &first)
{
    dfs(order, depth, root, 0);

    first.resize(size, -1);

    for (size_t i = 0; i < order.size(); i++)
    {
        if (first[order[i]] == -1)
        {
            first[order[i]] = i;
        }
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

void Treap::clean(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    clean(node->left);
    clean(node->right);

    delete node;
    node = nullptr;
}

Treap::~Treap()
{
    clean(root);
}
