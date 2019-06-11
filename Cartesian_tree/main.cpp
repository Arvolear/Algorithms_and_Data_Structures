#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <climits>

#include "cartesiantree.hpp"

using namespace std;

vector < string > decompose(string &s)
{
    vector < string > ans;
    string tmp = "";
        
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            tmp += s[i];
        }
        else
        {
            ans.push_back(tmp);
            tmp = "";
        }
    }

    ans.push_back(tmp);
    return ans;
}

int gen()
{
    double r = double(rand()) / double(RAND_MAX);

    return int(r * INT_MAX);
}

int main()
{
    Treap *T = new Treap();

    string help = "\nAvalibale options:\n \
        1) 'print' - prints the tree\n \
        2) 'build' - builds a tree from the provided priorities\n \
        3) 'insert [key]' - adds an element to the tree with key key\n \
        4) 'remove [key]' - removes an element with key key if found\n \
        5) 'q' - quits the program\n \
        6) 'h' - pring this message\n\n";

    string in = "h";
    while (true)
    {
        vector < string > input = decompose(in);

        if (input[0] == "print")
        {
            cout << endl;
            T->print(T->getRoot(), 0);
        }
        
        if (input[0] == "build")
        {
            vector < Node* > nodes;

            for (int i = 1; i < input.size(); i++)
            {
                nodes.push_back(new Node(i - 1, stol(input[i])));
            }
                
            T->build(nodes);
        }

        if (input[0] == "insert")
        {
            Node* root = T->getRoot();

            int g = gen();
            //cout << "G " << g << endl;

            T->insert(root, new Node(stol(input[1]), g));
        }

        if (input[0] == "remove")
        {
            T->remove(T->getRoot(), stol(input[1]));
        }

        if (input[0] == "q")
        {
            cout << "Quitting...\n";
            break;
        }

        if (input[0] == "h")
        {
            cout << help;
        }

        getline(cin, in);
    }


    delete T;

    return 0;
}
