#pragma once

#include <iostream>
#include <queue>

using namespace std;

template < typename Key, typename Val >
class RedBlack
{
    private:
        enum Color { BLACK, RED };

        struct Node
        {
            Node* parent;
            Node* left;
            Node* right;

            Color color;

            Key key;
            Val val;

            Node()
            {
                parent = left = right = nullptr;
                color = RED;
                key = Key();
                val = Val();
            }

            Node(Key key)
            {
                parent = left = right = nullptr;
                color = RED;
                this->key = key;
                val = Val(); 
            }
            
            Node(Key key, Val val)
            {
                parent = left = right = nullptr;
                color = RED;
                this->key = key;
                this->val = val;
            }
        };
        
        Node* root;

        Node* getParent(Node* node) const;
        Node* getGrandParent(Node* node) const;
        Node* getSibling(Node* node) const;
        Node* getUncle(Node* node) const;

        void rotateLeft(Node* node);
        void rotateRight(Node* node);

        Node* insertRecursive(Node* root, Node* node);
        void repair(Node* node);

        void repair1(Node* node);
        void repair2(Node* node);
        void repair3(Node* node);
        
        Node* findRecursive(Node* root, const Key& key) const;

        void clearRecursive(Node* root);

    public:
        RedBlack();

        void insert(const Key& key, const Val& val);
        void remove(const Key& key);
        bool find(const Key& key) const;

        Val& operator[](const Key& key);

        template < typename K, typename V >
        friend ostream& operator<<(ostream& out, const RedBlack<K, V>& tree);

        void clear();

        ~RedBlack();
};
