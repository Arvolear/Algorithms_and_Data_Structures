#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "LongString.h"
#include "PrimeRand.h"

vll NKM(vll n, vll k, vll m)
{
	vll rez(1), one(1), two(1);
	rez[0] = 1;
	one[0] = 1;
	two[0] = 2;

	while (k >= one)
	{
		if (k % two == one)
			rez = rez * n % m;

		n = n * n % m;
		k = k / two;
	}

	return rez;
}

vll Randstr(vll start, vll end)
{
	vll two(1), one(1);
	one[0] = 1;
	two[0] = 2;

	long long r = (start.size()) + rand() % (end.size() - start.size());
	long long i, j, k;
	vll ans;
	//cout << r << endl;
	for (i = 0; i < r; i++)
	{
		if (i == 0)
		{
			j = 3 + rand() % 9999;
			k = 3 + rand() % 9999;
			ans.push_back(j * k);
		}

		else if (i == r)
		{
			j = 1 + rand() % 9999;
			k = 1 + rand() % 9999;
			ans.push_back(j * k);
		}

		else
		{
			j = rand() % 9999;
			k = rand() % 9999;
			ans.push_back(j * k);
		}
	}

	if (ans % two == one)
		ans = ans - one;
	return ans;
}

bool RM(vll n)
{
	long long k = 10, i, j;
	bool f;
	vll s(1), t(1), n1, nul(1), one(1), two(1), three(1), a, x, check(1);
	one[0] = 1;
	two[0] = 2;
	three[0] = 3;
	t[0] = 1;
	n1 = n - one;

	if (n < two)
		return false;

	for (i = 2; i < 256; i++)
	{
		if (ReadLong(to_string(i)) == n)
			return true;

		check[0] = i;
		if (n % check == nul)
			return false;
	}

	while (true)
	{
		if (n1 % two == one)
		{
			t = n1;
			break;
		}

		n1 = n1 / two;
		s = s + one;
	}

	//cout << "s ; t\n" << PrintLong(s) << ' ' << PrintLong(t) << endl << endl;

	for (i = 0; i < k; i++)
	{
		f = false;

		a = Randstr(two, n - two);
		//cout << "a " << PrintLong(a) << endl;

		x = NKM(a, t, n);

		if (x == one || x == n - one)
			continue;

		for (j = 0; j < stol(PrintLong(s - one)); j++)
		{
			x = x * x % n;
			if (x == one)
				return false;
			else if (x == n - one)
			{
				f = true;
				break;
			}
		}

		if (f)
			continue;

		return false;
	}

	return true;
}

vll RSArand()
{
	vll one(1), two(1), four(1), r(1);
	one[0] = 1;
	two[0] = 2;
	four[0] = 4;
	r[0] = 1;
	string s = "1000000007";
	vll ss = ReadLong(s);
	//////////////////////////////////////////////////////////////////////////////////////
	while (ss.size() < 3)
	{
		r.clear();
		r.push_back(1);

		while (r % two == one)
			r = Randstr(one, (four * ss) + two);

		//	cout << "r " << PrintLong(r) << endl;
		vll n = ss * r + one;

		if (RM(n))
		{
			ss = n;
			cout << PrintLong(ss) << endl << endl;
		}

		//	cout << PrintLong(n) << endl;

	}

	return ss;
}
