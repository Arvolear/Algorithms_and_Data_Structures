#include <string>

#include "hashtable.hpp"
#include "hashtable.cpp"

int main()
{
    HashTable < string, int > HT0;

    HT0["10"] = 1;
    HT0["11"] = 2;
    HT0["12"] = 3;
    HT0["13"] = 4;
    HT0["14"] = 5;
    HT0["15"] = 6;
    HT0["16"] = 7;
    HT0["17"] = 8;
    HT0["18"] = 9;
    HT0["19"] = 10;
    
    cout << HT0 << endl;
    
    HT0.remove("18");

    cout << HT0 << endl;

    return 0;
}
