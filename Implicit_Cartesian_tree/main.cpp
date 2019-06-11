#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <climits>

#include "implicitcartesiantree.hpp"

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

int main()
{
    ImpTreap *IT = new ImpTreap();

    string help = "\nAvalibale options:\n \
        1) 'print' - prints the tree\n \
        2) 'insert [position, value]' - adds an element to the tree with position (index) as a key and priority as a value\n \
        3) 'remove [position]' - removes an element in the given position (index)\n \
        4) 'q' - quits the program\n \
        5) 'h' - pring this message\n\n";

    string in = "h";
    while (true)
    {
        vector < string > input = decompose(in);

        if (input[0] == "print")
        {
            cout << endl;
            IT->print(IT->getRoot());
        }
        
        if (input[0] == "insert")
        {
            IT->insert(new Node(stol(input[2])), stol(input[1])); // value is priority, index (position) is key
        }

        if (input[0] == "remove")
        {
            IT->remove(stol(input[1]));
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

    delete IT;

    return 0;
}
