#ifndef Encryption_H
#define Encryption_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector < long long > vll;

vll gcdex(vll a, vll b, vll & x, vll & y);

vll Revmod(vll a, vll m);

void data();

#endif
