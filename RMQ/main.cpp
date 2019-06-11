#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <climits>

#include "cartesiantree.hpp"
#include "sparsetable.hpp"
#include "fulltables.hpp"
#include "rmq.hpp"

using namespace std;

vector < string > decompose(string &s)
{
    vector < string > ans;
    string tmp = "";
        
    for (size_t i = 0; i < s.length(); i++)
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
    RMQ *rmq = new RMQ();

    string help = "\nAvalibale options:\n \
        1) 'build {..}' - preprocess RMQ from the provided array\n \
        2) 'min [left, right]' - get the minimum element from the given range\n \
        3) 'print' - print RMQ information\n \
        4) 'q' - quits the program\n \
        5) 'h' - pring this message\n\n";

    string in = "h";
    vector < Node* > nodes;
    
    while (true)
    {
        vector < string > input = decompose(in);

        if (input[0] == "print")
        {
            rmq->print();
            
            cout << endl;
            for (size_t i = 0; i < nodes.size(); i++)
            {
                cout << "[" << i << "] : " << nodes[i]->prior << endl; 
            }
            cout << endl;    
        }
        
        if (input[0] == "build")
        {
            for (size_t i = 1; i < input.size(); i++)
            {
                Node* node = new Node(i - 1, stol(input[i]));
                nodes.push_back(node);
            }
            
            cout << endl;
            for (size_t i = 0; i < nodes.size(); i++)
            {
                cout << "[" << i << "] : " << nodes[i]->prior << endl; 
            }
            cout << endl;
                
            rmq->build(nodes);
        }

        if (input[0] == "min")
        {
            int index = rmq->min(stol(input[1]), stol(input[2]));
            cout << endl << "[" << index << "] : " << nodes[index]->prior << endl;
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

    delete rmq;

    return 0;
}
