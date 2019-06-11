#include "segmenttree.hpp"

SegmentTree::SegmentTree(vector < int > &data)
{
    this->data = data;
}

void SegmentTree::build(int curVertex, int treeLeft, int treeRight)
{
    if (tree.size() <= curVertex) // if size of a tree is less than enough
    {
        tree.resize(curVertex + 1);
        //tree.push_back(0);
    }

    if (treeLeft == treeRight) // if it is a single element
    {
        tree[curVertex] = {data[treeLeft], treeLeft, treeRight}; // update it

        return;
    }

    int treeMiddle = (treeLeft + treeRight) / 2; // middle of a current segment

    build(curVertex * 2 + 1, treeLeft, treeMiddle); // left segment
    build(curVertex * 2 + 2, treeMiddle + 1, treeRight); // right segment

    // update a parent segment with data held in children
    tree[curVertex] = {
        tree[curVertex * 2 + 1].value + tree[curVertex * 2 + 2].value,
        treeLeft, 
        treeRight
    };
}

int SegmentTree::getSum(int curVertex, int left, int right)
{
    int treeLeft = tree[curVertex].leftID; 
    int treeRight = tree[curVertex].rightID; 

    if (treeLeft > treeRight || (treeLeft > right || treeRight < left)) // if a given segment doesn't intersect with current vertex segment
    {
        return 0;
    }

    if (treeLeft >= left && treeRight <= right) // if a given segment is inside a current node segment
    {
        return tree[curVertex].value;
    }

    int res = getSum(curVertex * 2 + 1, left, right) + getSum(curVertex * 2 + 2, left, right); 

    return res;
}

void SegmentTree::updateVertex(int curVertex, int index, int value)
{
    /* single cell */
    if (tree[curVertex].leftID == tree[curVertex].rightID)
    {
        tree[curVertex].value = value;
        data[tree[curVertex].leftID] = value;

        return;
    }

    int treeMiddle = (tree[curVertex].leftID + tree[curVertex].rightID) / 2;

    if (index <= treeMiddle)
    {
        updateVertex(curVertex * 2 + 1, index, value);
    }
    else
    {
        updateVertex(curVertex * 2 + 2, index, value);
    }

    tree[curVertex].value = tree[curVertex * 2 + 1].value + tree[curVertex * 2 + 2].value;
}

void SegmentTree::print()
{
    cout << "\nThe given array:\n";
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;

    cout << "Our segment tree:\n";
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i].value << ' ';
    }
    cout << endl << endl;
}

SegmentTree::~SegmentTree(){}
