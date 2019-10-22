#include "red-black.hpp"
#include "red-black.cpp"

#include <chrono>

int main()
{
    RedBlack < int, int > RB;
    auto start = chrono::system_clock::now();

    for (int i = 0; i < 1000000; i++)
    {
        RB.insert(i, i);
    }
    
    auto now = chrono::system_clock::now();
    chrono::duration < double > diff = now - start;
    cout << "Time to insert 1 mil : " << diff.count() << endl;
    
    start = chrono::system_clock::now();

    for (int i = 0; i < 1000000; i++)
    {
        RB.find(i);
    }
    
    now = chrono::system_clock::now();
    diff = now - start;
    cout << "Time to search 1 mil : " << diff.count() << endl;

    return 0; 
}
