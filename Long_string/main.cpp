#include "longstring.h"
#include <fstream>

using namespace std;

int main()
{
    //ifstream cin("./file");

    int n;
    cin >> n;

    LS ls(n);
    
    string s;
    string s1;

    cin >> s >> s1;
    
    vector < long long > o;
    vector < long long > p;

    o = ls.makenum(s);
    p = ls.makenum(s1);
    
    /*vector < long long > ll = ls.sum(o, p);

    cout << ls.makestr(ll) << endl << endl;*/

    cout << endl << endl;

    cout << ls.makestr(ls.sum(o, p)) << endl << endl;

    cout << ls.makestr(ls.sub(o, p)) << endl << endl;

    cout << ls.makestr(ls.mul(o, p)) << endl << endl;

    cout << ls.makestr(ls.div(o, p)) << endl;

    return 0;
}
