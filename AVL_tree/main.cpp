#include <string>
#include <chrono>

#include "AVL.hpp"

using namespace std;

void printAVL(AVL& tree)
{
    cout << "{\n";

    tree.print(tree.getRoot());

    if (tree.getRoot() != nullptr)
    {
        cout << "\t\"height\": " << tree.getRoot()->height << ",\n";

        cout << "\t\"root\": " << tree.getRoot()->key << ",\n";
    }

    cout << "\t\"size\": " << tree.getSize() << "\n";

    cout << "}\n";
}

int main()
{
    AVL tree;

    auto start = chrono::system_clock::now();
    
    for (int i = 0; i < 1000000; i++)
    {
        tree.insert(tree.getRoot(), i);
    }
    
    auto now = chrono::system_clock::now();
    chrono::duration < double > diff = now - start;
    cout << "Time to insert 1 mil : " << diff.count() << endl;
    
    start = chrono::system_clock::now();
    
    for (int i = 0; i < 1000000; i++)
    {
        tree.find(tree.getRoot(), i);
    }
    
    now = chrono::system_clock::now();
    diff = now - start;
    cout << "Time to search 1 mil : " << diff.count() << endl;

    return 0;
}
