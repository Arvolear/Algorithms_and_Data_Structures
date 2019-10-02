#include "longstring.h"
#include <fstream>
#include <ctime>

using namespace std;

string gen()
{
    string s = "";

    int length = 1 + rand() % 50;

    for (int i = 0; i < length; i++)
    {
        int a = rand() % 10;

        if (i == 0 && a == 0)
            a++;

        s += char(a + 48);
    }

    return s;
}

int main()
{
    srand(time(NULL));

    int n;
    cin >> n;

    LS ls(n);
    
    for (int i = 0; i < 100; i++)
    {
        ofstream input("./tests/" + to_string(i) + ".in");

        string s = gen();
        string s1 = gen();

        vector < long long > o;
        vector < long long > p;

        o = ls.makenum(s);
        p = ls.makenum(s1);

        if (ls.lt(o, p))
        {
            swap(p, o);
        }

        input << s << endl << s1; 
        
        ofstream output("./tests/" + to_string(i) + ".out");

        output << ls.makestr(ls.sum(o, p)) << endl;
        output << ls.makestr(ls.sub(o, p)) << endl;
        output << ls.makestr(ls.mul(o, p)) << endl;
        output << ls.makestr(ls.div(o, p));
    }

    return 0;
}
