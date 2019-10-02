#include "red-black.hpp"
#include "red-black.cpp"

int main()
{
    RedBlack < string, int > RB;

    RB["a"] = 1;
    RB["B"] = 2;
    RB["c"] = 3;
    RB["LOL"] = 4;

    RB["whatever you want"] = 123;

    cout << RB << endl;

    return 0; 
}
