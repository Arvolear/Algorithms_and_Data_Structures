#include <iostream>
#include <vector>
#include <string>

using namespace std;

void pref_func(string s, vector < int > &pi)
{
    pi.resize(s.length());

    pi[0] = 0;

    for (int i = 1; i < s.length(); i++)
    {
        int pos = pi[i - 1];
        while (pos > 0 && s[pos] != s[i])
            pos = pi[pos - 1];

        if (s[pos] == s[i])
            pi[i] = pos + 1;
        else
            pi[i] = 0;
    }
}

int main()
{
    string s;
    vector < int > pi;

    cin >> s;

    pref_func(s, pi);

    for (int i = 0; i < pi.size(); i++)
        cout << pi[i];

    cout << endl;


    return 0;

}



