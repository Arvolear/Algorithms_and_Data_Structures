#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LS
{
    private:
        int base;
        
        void extnum(vector < long long > &v, vector < long long > &w);

        vector < long long > normalsum(vector < long long > &v, vector < long long > &w);

        vector < long long > normalsub(vector < long long > &v, vector < long long > &w);
        
        vector < long long > normalmul(vector < long long > &v, vector < long long > &w);

        vector < long long > karatsubamul(vector < long long > &v, vector < long long > &w);


        vector < long long > normaldiv(vector < long long > &v, vector < long long > &w);

        void finalize (vector < long long > &v);

    public:
        LS(int b);
       
        long long bins(vector < long long > &v, vector < long long > &w);

        bool lt(vector < long long > &v, vector < long long > &w);
        
        bool eq(vector < long long > &v, vector < long long > &w);

        vector < long long > makenum(string s);

        vector < long long > sum(vector < long long > &v, vector < long long > &w);

        vector < long long > sub(vector < long long > &v, vector < long long > &w);

        vector < long long > mul(vector < long long > &v, vector < long long > &w);

        vector < long long > div(vector < long long > &v, vector < long long > &w);

        string makestr(const vector < long long > &v);
        ~LS();
};
