#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));

    ofstream cout("./file", ios::trunc);

    string s;
    string s1;

    for (int i = 0; i < 1000; i++)
    {
        int a = rand() % 10;

        if (i == 0 && a == 0)
            a++;

        int b = rand() % 10;
        if (i == 0 && b == 0)
            b++;

        s += char(a + 48);
        s1 += char(b + 48);
    }

    cout << 8 << endl << s << endl << s1 << endl; 

    return 0;
}
