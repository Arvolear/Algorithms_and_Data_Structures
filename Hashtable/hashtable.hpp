#pragma once

#include <iostream>
#include <list>
#include <functional>

using namespace std;

template < typename Key, typename Val, typename Hash = hash<Key> >
class HashTable
{
    private:
        list < pair < Key, Val > >* table;

        unsigned int amount;
        unsigned int capacity;
        double maxLoadFactor;

        Hash hashFunction;

        void rehash();

    public:
        HashTable(unsigned int capacity = 10, Hash hashFunction = Hash());
        HashTable(const HashTable& HT);
        HashTable& operator=(const HashTable& HT);
         
        void insert(const Key& key, const Val& val);
        void remove(const Key& key);
        bool find(const Key& key);

        Val& operator[](const Key& key);

        template < typename K, typename V, typename H >
        friend ostream& operator<<(ostream& out, const HashTable<K, V, H>& HT);

        ~HashTable();
};
