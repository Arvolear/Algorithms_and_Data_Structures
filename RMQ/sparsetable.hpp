#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class SparseTable
{
    private:
        size_t log2n;
        size_t blockSize;
        size_t blockAmount;

        vector < int > minOnBlock;
        vector < vector < int > > sparse;

        void decompose(vector < int > &depth);

    public:
        SparseTable();

        void build(vector < int > &depth);

        int min(int l, int r, vector < int > &depth);

        void print();

        ~SparseTable();
};
