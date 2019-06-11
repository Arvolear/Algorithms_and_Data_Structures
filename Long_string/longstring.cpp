#include "longstring.h"

using namespace std;

LS::LS(int b)
{
    base = b; 
}

LS::~LS()
{}

vector < long long > LS::makenum(string s)
{
    vector < long long > res;
    long long n = 0;
    int d = 1;
    int t = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        int e = d;

        while (e > 1)
        {
            t *= 10;
            e--;
        }

        n += (long(s[i] - '0')) * t;
        d++;

        if ((d - 1) == base)
        {
            res.push_back(n);
            n = 0;
            d = 1;
        }
        t = 1;
    }

    if (n != 0)
    {
        res.push_back(n);
    }

    return res;
}

vector < long long > LS::sum(vector < long long > &v, vector < long long > &w)
{
    vector < long long > res = normalsum(v, w);

    finalize(res);

    return res;
}

vector < long long > LS::normalsum(vector < long long > &v, vector < long long > &w)
{
    int len = max(v.size(), w.size());

    vector < long long > res;

    res.resize(len);

    v.resize(len);
    w.resize(len);

    for (int i = 0; i < v.size(); i++)
    {
        res[i] += v[i] + w[i];
    }

    return res;
}

vector < long long > LS::sub(vector < long long > &v, vector < long long > &w)
{
    vector < long long > res = normalsub(v, w);

    finalize(res);

    return res;
}

vector < long long > LS::normalsub(vector < long long > &v, vector < long long > &w)
{
    int len = max(v.size(), w.size());

    vector < long long > res;
    res.resize(len);

    int ni = 1;

    int b = base;
    while(b)
    {
        ni *= 10;
        b--;
    }

    ni--;
    
    vector < long long > nine(len, ni);

    v.resize(len);
    w.resize(len);

    vector < long long > subnine(len);

    for (int i = 0; i < v.size(); i++)
    {
        subnine[i] = nine[i] - v[i];
    }

    subnine = sum(subnine, w);

    for (int i = 0; i < v.size(); i++)
    {
        res[i] = nine[i] - subnine[i];
    }

    return res;
}

bool LS::lt(vector < long long > &v, vector < long long > &w)
{
    finalize(v);
    finalize(w);

    if (v.size() > w.size())
        return false;
    
    if (v.size() == w.size())
    {
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] > w[i])
                return false;

            if (v[i] < w[i])
                return true;
        }
    }

    return true;
}

bool LS::eq(vector < long long > &v, vector < long long > &w)
{
    finalize(v);
    finalize(w);

    if (v.size() != w.size())
        return false;
    
    if (v.size() == w.size())
    {
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] != w[i])
                return false;
        }
    }

    return true;
}

void LS::extnum(vector < long long > &v, vector < long long > &w)
{
    int s = max(v.size(), w.size());

    int d = 1;
    while (d < s)
    {
        d *= 2;
    }

    v.resize(d);
    w.resize(d);
}

vector < long long > LS::mul(vector < long long > &v, vector < long long > &w)
{
    extnum(v, w);
    vector < long long > res = karatsubamul(v, w);

    finalize(res);
    finalize(v);
    finalize(w);

    return res;
}

vector < long long > LS::normalmul(vector < long long > &v, vector < long long > &w)
{ 
    vector < long long > res;


    int len = v.size();
    res.resize(2 * len);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            res[i + j] += v[i] * w[j];
        }
    }
    

    return res;
}


vector < long long > LS::karatsubamul(vector < long long > &v, vector < long long > &w)
{
    int len = v.size();

    vector < long long > res;
    res.resize(2 * len);

    if (len <= 64)
    {
        return normalmul(v, w);
    }

    int k = len / 2;

    vector < long long > vr {v.begin(), v.begin() + k};

    vector < long long > vl {v.begin() + k, v.end()};
    
    vector < long long > wr {w.begin(), w.begin() + k};

    vector < long long > wl {w.begin() + k, w.end()};

    vector < long long > p1 = karatsubamul(vl, wl);
    vector < long long > p2 = karatsubamul(vr, wr);

    vector < long long > vlr;
    vlr.resize(k);
    vector < long long > wlr;
    wlr.resize(k);

    for (int i = 0; i < k; i++)
    {
        vlr[i] = vl[i] + vr[i];
        wlr[i] = wl[i] + wr[i];
    }

    vector < long long > p3 = karatsubamul(vlr, wlr);

    for (int i = 0; i < len; i++)
    {
        p3[i] -= p1[i] + p2[i];
    }

    for (int i = 0; i < len; i++)
    {
        res[i] = p2[i];
    }

    for (int i = len; i < 2 * len; i++)
    {
        res[i] = p1[i - len];
    }

    for (int i = k; i < len + k; i++)
    {
        res[i] += p3[i - k];
    }

    return res;
}
        
long long LS::bins(vector < long long > &v, vector < long long > &w)
{

    int l = 0;

    int b = base;
    int r = 1; 
    while (b)
    {
        b--;
        r *= 10;
    }

    r--;
        
    vector < long long > bak;
    vector < long long > m;

    while (r - 1 > l)
    {
        bak.push_back((r + l) / 2);
        m = mul(bak, v);

        //cout << l << ' ' << r << ' ' << makestr(m) << ' ' << makestr(w) << endl;

        if (lt(m, w))
        {
            l = (l + r) / 2;
        }
        else if (eq(m, w))
        {
            return r;
        }
        else
        {
            r = (l + r) / 2;
        }

        bak.clear();
        m.clear();
    }

    bak.clear();
    bak.push_back(r);
    m = mul(bak, v);

    while (!lt(m, w))
    {
        r = (l + r) / 2;
        bak.clear();
        bak.push_back(r);
        m = mul(bak, v);
    }

    vector < long long > res;
    res.push_back(r);
    

    return r;
}

vector < long long > LS::normaldiv(vector < long long > &v, vector < long long > &w)
{
    vector < long long > pv{v.end() - w.size() + 1, v.end()};
    vector < long long > res;

    if (!lt(w, pv) && !eq(w, pv))
    {
        reverse(pv.begin(), pv.end());
        pv.push_back(v[v.size() - (w.size())]);
        reverse(pv.begin(), pv.end());
    }
    
    int n = pv.size();
            
    vector < long long > bak;

    long long a = bins(w, pv);

    res.push_back(a);
    bak.push_back(a);

    bak = mul(w, bak); 
                
    pv = sub(pv, bak);

    for (int i = v.size() - n - 1; i >= 0; i--)
    {
        bak.clear();

        reverse(pv.begin(), pv.end());
        pv.push_back(v[i]);
        reverse(pv.begin(), pv.end());

        /*for (int j = 0; j < pv.size(); j++)
            cout << pv[j] << ' ';

        cout << endl;*/

        long long a = bins(w, pv);

        //cout << "a" << a << endl;

        res.push_back(a);
        bak.push_back(a);

        bak = mul(w, bak); 
             
        pv = sub(pv, bak);
    }

    reverse(res.begin(), res.end());

    return res;
}
        
vector < long long > LS::div(vector < long long > &v, vector < long long > &w)
{
    vector < long long > res = normaldiv(v, w);

    finalize(res);

    return res;
}

void LS::finalize (vector < long long > &v)
{
    int b = base;
    int t = 1;

    if (v.size() > 0)
    {
        while (b > 0)
        {
            t *= 10;
            b--;
        }
        while (v[v.size() - 1] == 0)
        v.pop_back();
    } 
    for (int i = 0; i < v.size(); i++)
    {
        if (i == v.size() - 1)
        {
            if (v[i] >= t)
                v.push_back(v[i] / t);
        }
        else
            v[i + 1] += v[i] / t;
        
        v[i] %= t;
    }
}

string LS::makestr(const vector < long long > &v)
{
    string s = "";

    if (v.size() == 0)
        return "0";

    int j = v.size() - 1;
    while (v[j] == 0)
    {
        j--;
    }

    for (int i = j; i >= 0; i--)
    {
        string sh = "";
        int count = 0;
        long long n = v[i];

        while (n > 0)
        { 
            sh += char(n % 10 + 48);
            n /= 10;
            count++;
        }

        while (count < base)
        {
            if (i == j)
                break;

            sh += '0';
            count++;
        }


        reverse(sh.begin(), sh.end());
        s += sh;
    }

    if (s == "" && v.size() == 1)
        s += '0';

    return s;
}
