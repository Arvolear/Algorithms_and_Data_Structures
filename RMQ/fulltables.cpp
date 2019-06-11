#include "fulltables.hpp"

FullTables::FullTables(){}

void FullTables::build(vector < int > &depth)
{
    log2n = max(1, (int)log2(depth.size()));

    blockSize = max(1, log2n / 2);
    blockAmount = depth.size() / blockSize + 1;

    blockToMask.resize(blockAmount);

    for (size_t i = 0, j = 0; i < depth.size(); i++, j = (j + 1) % blockSize)
    {
        int curBlock = i / blockSize;
        
        if (j > 0 && depth[i - 1] < depth[i])
        {
            blockToMask[curBlock] += (1 << (j - 1));
        }
    }

    for (size_t k = 0; k < blockToMask.size(); k++)
    {
        int curMask = blockToMask[k];

        if (tables.find(curMask) == tables.end())
        {
            tables[curMask].resize(blockSize);

            for (size_t i = 0; i < tables[curMask].size(); i++)
            {
                tables[curMask][i].resize(blockSize);
                tables[curMask][i][i] = i;
            }
            
            for (size_t i = 0; i < tables[curMask].size(); i++)
            {
                for (size_t j = i + 1; j < tables[curMask][i].size(); j++)
                {
                    int minIndex = tables[curMask][i][j - 1];

                    if (k * blockSize + j < depth.size())
                    {
                        if (depth[k * blockSize + j] < depth[k * blockSize + minIndex])
                        {
                            minIndex = j;
                        }
                    }

                    tables[curMask][i][j] = minIndex;
                }
            }
        }
    }
}

int FullTables::min(int l, int r, vector < int > &depth)
{
    int L = l / blockSize;
    int R = r / blockSize;

    int LTable = blockToMask[L];
    int RTable = blockToMask[R];

    int LIndex = tables[LTable][l % blockSize][blockSize - 1] + L * blockSize;
    int RIndex = tables[RTable][r % blockSize][blockSize - 1] + R * blockSize;

    if (depth[LIndex] < depth[RIndex])
    {
        return LIndex;    
    }
    else
    {
        return RIndex;
    }
}

void FullTables::print()
{
    cout << "BlockSize: " << blockSize << ' ';
    cout << "BlockAmount: " << blockAmount << endl;

    for (size_t i = 0; i < blockToMask.size(); i++)
    {
        cout << blockToMask[i] << ' ';
    }
    cout << endl;

    for (auto &table: tables)
    {
        cout << endl << table.first << endl;

        for (size_t i = 0; i < table.second.size(); i++)
        {
            for (size_t j = 0; j < table.second[i].size(); j++)
            {
                cout << table.second[i][j] << ' ';    
            }
            cout << endl;
        }
    }
    cout << endl;
}

FullTables::~FullTables(){}
