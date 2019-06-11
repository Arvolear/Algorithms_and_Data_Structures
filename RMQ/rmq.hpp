#include <iostream>
#include <vector>

using namespace std;

class RMQ
{
    private:
        vector < int > order;
        vector < int > depth;
        vector < int > first;

        Treap* treap;
        SparseTable* sparseTable;
        FullTables* fullTables;

    public:
        RMQ();

        void build(vector < Node* > &nodes);

        int min(int l, int r);

        void print();

        ~RMQ();
};
