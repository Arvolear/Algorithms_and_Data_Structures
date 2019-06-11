#include <fstream>
#include <cctype>
#include <string>

#include "AVL.hpp"

using namespace std;

int findNum(string &line)
{
    string num = "";

    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == '-' || isdigit(line[i]))
        {
            num += line[i];        
        }
    }

    return stoi(num);
}

void parceAndMakeAVL(string filename, AVL &tree)
{
    ifstream in(filename);
    string line;
    int key;

    while (getline(in, line))
    {
        if (line.find("key") != string::npos)
        {
            key = findNum(line);
        }
        
        if (line.find("operation") != string::npos)
        {
            if (line.find("Insert") != string::npos)
            {
                tree.insert(tree.getRoot(), key);
            }
            
            if (line.find("Delete") != string::npos && line.find("DeleteMin") == string::npos)
            {
                tree.remove(tree.getRoot(), key);
            }
            
            if (line.find("DeleteMin") != string::npos)
            {
                tree.removeMinimum(tree.getRoot());
            }
        }

        line = "";
    }
}

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

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Wrong argument(s)\n";
        return 0;
    }

    AVL tree;

    parceAndMakeAVL(argv[1], tree);
    printAVL(tree);

    return 0;
}
