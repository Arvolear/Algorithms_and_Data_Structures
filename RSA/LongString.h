#ifndef LongString_H
#define LongString_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector < long long > vll;

bool operator >(vll a, vll b);

bool operator >=(vll a, vll b);

bool operator <(vll a, vll b);

bool operator <=(vll a, vll b);

bool operator ==(vll a, vll b);

bool operator !=(vll a, vll b);

vll ReadLong(string s);

string PrintLong(vll a);

vll Bins(vll a, vll b);

vll operator +(vll a, vll b);

vll operator -(vll a, vll b);

vll operator *(vll a, vll b);

vll operator /(vll a, vll b);

vll operator %(vll a, vll b);

#endif