#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class FullTables
{
    private:
        int log2n;
        int blockSize;
        int blockAmount;

        unordered_map < int, vector < vector < int > > > tables;
        vector < int > blockToMask;

    public:
        FullTables();

        void build(vector < int > &depth);

        int min(int l, int r, vector < int > &depth);

        void print();

        ~FullTables();
};
