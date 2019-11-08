#include "hashtable.hpp"

template < typename Key, typename Val, typename Hash >
HashTable<Key, Val, Hash>::HashTable(unsigned int capacity, Hash hashFunction)
{
    this->amount = 0;
    this->capacity = capacity;
    this->maxLoadFactor = 0.7;

    this->hashFunction = hashFunction;

    table = new list < pair < Key, Val > >[capacity];
}
        
template < typename Key, typename Val, typename Hash >
HashTable<Key, Val, Hash>::HashTable(const HashTable& HT)
{
    this->amount = HT.amount;
    this->capacity = HT.capacity;
    this->maxLoadFactor = HT.maxLoadFactor;
    this->hashFunction = HT.hashFunction;

    table = new list < pair < Key, Val > >[capacity];

    for (unsigned int i = 0; i < capacity; i++)
    {
        table[i] = HT.table[i];
    }
}

template < typename Key, typename Val, typename Hash >
HashTable<Key, Val, Hash>& HashTable<Key, Val, Hash>::operator=(const HashTable& HT)
{
    delete[] table;

    this->amount = HT.amount;
    this->capacity = HT.capacity;
    this->maxLoadFactor = HT.maxLoadFactor;
    this->hashFunction = HT.hashFunction;

    table = new list < pair < Key, Val > >[capacity];

    for (unsigned int i = 0; i < capacity; i++)
    {
        table[i] = HT.table[i];
    }

    return *this;
}

template < typename Key, typename Val, typename Hash >
void HashTable<Key, Val, Hash>::rehash()
{
    HashTable<Key, Val, Hash> tmp(*this);
    
    delete[] table;
    capacity *= 2;
    table = new list < pair < Key, Val > >[capacity];
    
    for (unsigned int i = 0; i < tmp.capacity; i++)
    {
        for (auto& j: tmp.table[i])
        {
            insert(j.first, j.second);
        }
    }
}

template < typename Key, typename Val, typename Hash >
void HashTable<Key, Val, Hash>::insert(const Key& key, const Val& val)
{
    amount++;

    if ((double)amount / (double)capacity > maxLoadFactor)
    {
        rehash();
    }

    unsigned int hashVal = hashFunction(key);
    hashVal %= capacity;

    table[hashVal].push_back({key, val});
}

template < typename Key, typename Val, typename Hash >
void HashTable<Key, Val, Hash>::remove(const Key& key)
{
    unsigned int hashVal = hashFunction(key);
    hashVal %= capacity;

    if (!table[hashVal].empty())
    {
        for (auto it = table[hashVal].begin(); it != table[hashVal].end(); it++)
        {
            if ((*it).first == key)
            {
                table[hashVal].erase(it);
                amount--;
                return;
            }
        }
    }
}

template < typename Key, typename Val, typename Hash >
bool HashTable<Key, Val, Hash>::find(const Key& key)
{
    unsigned int hashVal = hashFunction(key);
    hashVal %= capacity;
     
    if (!table[hashVal].empty())
    {
        for (auto it = table[hashVal].begin(); it != table[hashVal].end(); it++)
        {
            if ((*it).first == key)
            {
                return true;
            }
        }
    }
    
    return false;
}

template < typename Key, typename Val, typename Hash >
Val& HashTable<Key, Val, Hash>::operator[](const Key& key)
{
    unsigned int hashVal = hashFunction(key);
    hashVal %= capacity;
     
    if (!table[hashVal].empty())
    {
        for (auto it = table[hashVal].begin(); it != table[hashVal].end(); it++)
        {
            if ((*it).first == key)
            {
                return it->second;
            }
        }
    }
    
    amount++;

    if ((double)amount / (double)capacity > maxLoadFactor)
    {
        rehash();
    }

    hashVal = hashFunction(key);
    hashVal %= capacity;

    table[hashVal].push_back({key, Val()});

    return (--table[hashVal].end())->second;
}

    template < typename K, typename V, typename H >
ostream& operator<<(ostream& out, const HashTable<K, V, H>& HT)
{
    if (!HT.amount)
    {
        out << "Empty!" << endl;
        return out;
    }

    for (unsigned int i = 0; i < HT.capacity; i++)
    {
        if (!HT.table[i].empty())
        {
            out << "[" << i << "]: ";

            for (auto& j: HT.table[i])
            {
                out << j.first << "=" << j.second << " "; 
            }

            out << endl;
        }
    }

    return out;
}

    template < typename Key, typename Val, typename Hash >
HashTable<Key, Val, Hash>::~HashTable()
{
    delete[] table;
}
