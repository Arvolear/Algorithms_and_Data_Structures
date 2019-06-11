#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "LongString.h"
#include "PrimeRand.h"

using namespace std;

typedef vector < long long > vll;

vll gcdex(vll a, vll b, vll & x, vll & y)
{
	vll nul(1), one(1);
	nul[0] = 0;
	one[0] = 1;

	if (b == one)
	{
		x = nul; y = one;
		return b;
	}

	vll x1, y1;

	vll d = gcdex(b % a, a, x1, y1);
	//cout << "x1 y1 " << PrintLong(x1) << ' ' << PrintLong(y1) << endl;
	x = y1 - (b / a) * x1;
	y = x1;

	return d;
}

vll Revmod(vll a, vll m)
{
	vll mone(1), one(1), x, y;
	mone[0] = -1;
	one[0] = 1;

	vll g = gcdex(a, m, x, y);
	//cout << "g  " << PrintLong(g) << endl;
	if (g != one)
		return mone;

	else
	{
	//	cout << "x y " << PrintLong(x) << ' ' << PrintLong(y) << endl;
		x = (x % m + m) % m;
		return x;
	}
}

void data()
{
	bool f = false;
	vll one(1), p, p1, p2, prime1, prime2, n, n1, d, e;
	vector < vector < long long > > input, encryption, output;
	one[0] = 1;
	long long i;
	string s, s1;

    cout << "Input string to be encrypted:\n";
	getline(cin, s);

	prime1 = RSArand();
	prime2 = RSArand();

	//prime1.push_back(3);
	//prime2.push_back(11);

	n = prime1 * prime2;
	n1 = (prime1 - one) * (prime2 - one);

	d = RSArand();
	//d.push_back(7);
	e = Revmod(d, n1);

	//cout << "\nprime1 " << PrintLong(prime1) << endl << endl;
	//cout << "prime2 " << PrintLong(prime2) << endl << endl;
	//cout << "n " << PrintLong(n) << endl << endl;
	//cout << "n1 " << PrintLong(n1) << endl << endl;
	//cout << "d " << PrintLong(d) << endl << endl;
	//cout << "e " << PrintLong(e) << endl << endl;

	cout << "opened\n" << PrintLong(e) << endl << PrintLong(n) << endl << endl;
	cout << "closed\n" << PrintLong(d) << endl << PrintLong(n) << endl << endl;

	cout << "\ninput\n" << endl;
	for (i = 0; i < s.length(); i++)
	{
		input.push_back(ReadLong((to_string(s[i]))));
		cout << '[' << i << ']' << ' ' << PrintLong(input[i]) << ' ' 
			<< s[i] << endl;
		encryption.push_back(NKM(input[i], e, n));
		//input.clear();
	}

	cout << "\nencryption\n";
	for (i = 0; i < encryption.size(); i++)
	{
		cout << PrintLong(encryption[i]) << endl;
	}

	cout << "\noutput\n";
	for (i = 0; i < encryption.size(); i++)
	{
		output.push_back(NKM(encryption[i], d, n));
		cout << '[' << i << ']' << ' ' << PrintLong(output[i]) << ' ' 
			<< char(stol(PrintLong(output[i]))) << endl;
		//cout << PrintLong(encryption[i]) << endl;
	}

	for (i = 0; i < output.size(); i++)
	{
		if (input[i] != output[i])
		{
			f = true;
			cout << "\nMistake\n";
			break;
		}
		//cout << PrintLong(encryption[i]) << endl;
	}

	if (!f)
		cout << "\nOK\n";
}
