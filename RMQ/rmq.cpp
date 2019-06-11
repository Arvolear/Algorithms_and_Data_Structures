#include "cartesiantree.hpp"
#include "sparsetable.hpp"
#include "fulltables.hpp"
#include "rmq.hpp"

RMQ::RMQ()
{
    treap = new Treap();
    sparseTable = new SparseTable();
    fullTables = new FullTables();
}

void RMQ::build(vector < Node* > &nodes)
{
    treap->build(nodes);
    treap->linearize(order, depth, first);

    sparseTable->build(depth);
    //fullTables->build(depth); 
}

int RMQ::min(int l, int r)
{
    int firstL = first[l];
    int firstR = first[r];

    int sparseIndex = sparseTable->min(firstL, firstR, depth);
    int fullIndex = fullTables->min(firstL, firstR, depth);

    if (sparseIndex != -1 && depth[sparseIndex] < depth[fullIndex])
    {
        return order[sparseIndex];
    }
    else
    {
        return order[fullIndex];
    }

    return 0;
}

void RMQ::print()
{
    treap->print(treap->getRoot(), 0);
    cout << endl;

    cout << "Order:\n";
    for (size_t i = 0; i < order.size(); i++)
    {
        cout << order[i] << ' '; 
    }
    cout << endl;
    
    cout << "Depth:\n";
    for (size_t i = 0; i < depth.size(); i++)
    {
        cout << depth[i] << ' '; 
    }
    cout << endl;
    
    cout << "First:\n";
    for (size_t i = 0; i < first.size(); i++)
    {
        cout << first[i] << ' '; 
    }
    cout << endl << endl;

    sparseTable->print(); 
    cout << endl;
    fullTables->print();
}

RMQ::~RMQ()
{
    delete treap;
    delete sparseTable;
    delete fullTables;
}
