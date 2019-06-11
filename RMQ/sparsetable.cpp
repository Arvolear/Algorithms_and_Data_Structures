#include "sparsetable.hpp"

SparseTable::SparseTable()
{
    blockSize = 0;
    blockAmount = 0;
    log2n = 0;
}

void SparseTable::decompose(vector < int > &depth)
{
    log2n = max(1, (int)log2(depth.size()));

    blockSize = max(1, (int)(log2n / 2));
    blockAmount = depth.size() / blockSize + 1;

    minOnBlock.resize(blockAmount, -1);

    for (size_t i = 0; i < depth.size(); i++)
    {  
        if (minOnBlock[i / blockSize] == -1 || 
               depth[minOnBlock[i / blockSize]] > depth[i])
        {
            minOnBlock[i / blockSize] = i;
        }
    }
}

void SparseTable::build(vector < int > &depth)
{
    decompose(depth);

    sparse.resize(blockAmount);

    for (size_t i = 0; i < blockAmount; i++)
    {
        sparse[i].resize(log2n, -1);
        sparse[i][0] = minOnBlock[i];
    }

    for (size_t j = 1; j <= log2n; j++)
    {
        for (size_t i = 0; i + (1 << (j - 1)) < blockAmount; i++)
        {
            size_t index = i + (1 << (j - 1));

            if (depth[sparse[i][j - 1]] <
                    depth[sparse[index][j - 1]])
            {
                sparse[i][j] = sparse[i][j - 1];
            } 
            else
            {
                sparse[i][j] = sparse[index][j - 1];
            }
        }
    }
}

int SparseTable::min(int l, int r, vector < int > &depth)
{
    int L = l / blockSize + 1;
    int R = r / blockSize + 1;

    if (L >= R - 1)
    {
        return -1;
    }

    int power = (int)log2(R - L - 1);
    int index = (1 << power) + 1;

    if (depth[sparse[L][power]] < depth[sparse[R - index][power]])
    {
        return sparse[L][power];
    }
    else
    {
        return sparse[R - index][power];
    }
}

void SparseTable::print()
{
    for (size_t i = 0; i < sparse.size(); i++)
    {
        cout << i << " | ";

        for (size_t j = 0; j < sparse[i].size(); j++)
        {
            cout << sparse[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

SparseTable::~SparseTable(){}
