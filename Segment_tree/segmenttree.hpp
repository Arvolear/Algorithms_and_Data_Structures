#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int value;
    int leftID, rightID;
};

class SegmentTree
{
    private:
        vector < int > data;
        vector < Node > tree;

    public:
        SegmentTree(vector < int > &data);

        void build(int curVertex, int treeLeft, int treeRight);
        int getSum(int curVertex, int left, int right);
        void updateVertex(int curVertex, int index, int value);

        void print();

        ~SegmentTree();
};
