#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "LongString.h"

using namespace std;

typedef vector < long long > vll;

bool operator >(vll a, vll b)
{
	if (a[a.size() - 1] >= 0 && b[b.size() - 1] >= 0)
	{
		if (a.size() < b.size())
			return false;

		if (a.size() > b.size())
			return true;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return false;

				else if (a[i] > b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}

	if (a[a.size() - 1] >= 0 && b[b.size() - 1] < 0)
		return true;

	if (a[a.size() - 1] <= 0 && b[b.size() - 1] >= 0)
		return false;

	if (a[a.size() - 1] < 0 && b[b.size() - 1] < 0)
	{
		if (a.size() < b.size())
			return true;

		if (a.size() > b.size())
			return false;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return false;

				else if (a[i] > b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}
}

bool operator >=(vll a, vll b)
{
	if (a[a.size() - 1] >= 0 && b[b.size() - 1] >= 0)
	{
		if (a.size() < b.size())
			return false;

		if (a.size() > b.size())
			return true;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return true;

				else if (a[i] > b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}

	if (a[a.size() - 1] >= 0 && b[b.size() - 1] <= 0)
		return true;

	if (a[a.size() - 1] < 0 && b[b.size() - 1] >= 0)
		return false;

	if (a[a.size() - 1] < 0 && b[b.size() - 1] < 0)
	{
		if (a.size() < b.size())
			return true;

		if (a.size() > b.size())
			return false;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return true;

				else if (a[i] > b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}

}

bool operator <(vll a, vll b)
{
	if (a[a.size() - 1] >= 0 && b[b.size() - 1] >= 0)
	{
		if (a.size() > b.size())
			return false;

		if (a.size() < b.size())
			return true;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return false;

				else if (a[i] < b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}

	if (a[a.size() - 1] >= 0 && b[b.size() - 1] < 0)
		return false;

	if (a[a.size() - 1] < 0 && b[b.size() - 1] >= 0)
		return true;

	if (a[a.size() - 1] < 0 && b[b.size() - 1] < 0)
	{
		if (a.size() < b.size())
			return false;

		if (a.size() > b.size())
			return true;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return false;

				else if (a[i] < b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}
}

bool operator <=(vll a, vll b)
{
	if (a[a.size() - 1] >= 0 && b[b.size() - 1] >= 0)
	{
		if (a.size() > b.size())
			return false;

		if (a.size() < b.size())
			return true;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return true;

				else if (a[i] < b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}

	if (a[a.size() - 1] >= 0 && b[b.size() - 1] < 0)
		return false;

	if (a[a.size() - 1] <= 0 && b[b.size() - 1] >= 0)
		return true;

	if (a[a.size() - 1] < 0 && b[b.size() - 1] < 0)
	{
		if (a.size() < b.size())
			return false;

		if (a.size() > b.size())
			return true;

		else
		{
			long long i = a.size();

			while (i >= 0)
			{
				i--;

				if (i == -1)
					return true;

				else if (a[i] < b[i])
					return true;

				else if (a[i] == b[i])
					continue;

				else
					return false;
			}
		}
	}

}

bool operator ==(vll a, vll b)
{
	if (a.size() != b.size())
		return false;

	for (long long i = a.size() - 1; i >= 0; i--)
		if (a[i] != b[i])
			return false;

	return true;
}

bool operator !=(vll a, vll b)
{
	if (a.size() != b.size())
		return true;

	for (long long i = a.size() - 1; i >= 0; i--)
		if (a[i] != b[i])
			return true;

	return false;
}

vll ReadLong(string s)
{
	long long i, j, osn = 100000000;
	vll rez;

	if (s[0] == '-')
		rez.resize((s.length() + 6) / 8);
	else
		rez.resize((s.length() + 7) / 8);

	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == '-')
			i++;

		rez[0] = rez[0] * 10 + long(s[i] - '0');

		for (j = 0; j < rez.size() - 1; j++)
		{
			rez[j + 1] = rez[j + 1] * 10 + rez[j] / osn;
			rez[j] %= osn;
		}
	}

	if (s[0] == '-')
		for (i = rez.size() - 1; i >= 0; i--)
			rez[i] *= -1;

	return rez;
}

string PrintLong(vll a)
{
	string ss = "";
	string print = "";
	/*cout << endl;
	for (long long i = 0; i < a.size(); i++)
	cout << a[i] << ' ';

	cout << endl;*/

	ss = ss + to_string(a[a.size() - 1]);

	if (a.size() > 1)
		for (long long i = a.size() - 2; i >= 0; i--)
		{
			if (a[i] < 0)
				a[i] *= -1;
			print = to_string(a[i]);
			//while (print.length() < 1)
				//print = '0' + print;

			ss = ss + print;
		}

	return ss;
}

vll Bins(vll a, vll b)
{
	long long l = 1, r = 99999999;

	vll lr(1), two(1), rez(1);

	two[0] = 2;

	if (a.size() == 1 && a[0] == 0)
	{
		two[0] -= 2;
		return two;
	}

	if (b * two > a)
	{
		two[0]--;
		return two;
	}

	while (r - l > 1)
	{
		lr[0] = (l + r) / 2;
		if (b * lr > a)
			r = lr[0];
		else
			l = lr[0];
	}

	rez[0] = r;
	if (rez * b > a)
		rez[0]--;

	return rez;
}

vll add(vll a, vll b)
{
	long long osn = 100000000, i = 0, j = 0;

	if (a < b)
		swap(a, b);

	vll rez(a.size() + b.size());

	b.push_back(0);

	for (i = 0; i < a.size(); i++)
	{
		rez[i + 1] = (rez[i] + a[i] + b[j]) / osn;
		rez[i] = (rez[i] + a[i] + b[j]) % osn;
		if (j < b.size() - 1)
			j++;
	}

	while (rez.size() > 1 && rez[rez.size() - 1] == 0)
		rez.erase(rez.end() - 1);

	return rez;
}

vll sub(vll a, vll b)
{
	bool f = false;
	long long i;

	if (a < b)
	{
		swap(a, b);
		f = true;
	}

	vll rez(a.size() + a.size());
	vll x(a.size());

	for (i = 0; i < a.size(); i++)
		x[i] = 99999999 - a[i];

	a = a + x;
	b = b + x;

	for (i = 0; i < a.size(); i++)
		rez[i] = a[i] - b[i];

	while (rez.size() > 1 && rez[rez.size() - 1] == 0)
		rez.erase(rez.end() - 1);

	if (f)
		for (i = rez.size() - 1; i >= 0; i--)
			rez[i] *= -1;

	return rez;
}

vll mult(vll a, vll b)
{
	vll rez(a.size() + b.size());
	long long i, j, dv, osn = 100000000;

	for (i = 0; i < a.size(); i++)
	{
		for (j = 0; j < b.size(); j++)
		{
			dv = a[i] * b[j] + rez[i + j];
			rez[i + j + 1] += dv / osn;
			rez[i + j] = dv % osn;
		}
	}

	while (rez.size() > 1 && rez[rez.size() - 1] == 0)
		rez.erase(rez.end() - 1);

	return rez;
}

vll div(vll a, vll b)
{
	vll x(1);
	vll d;
	vll rez;
	vll ost(1);
	vll nul(1);
	long long i = 0, j = 0, start;

	if (b.size() == 1 && b[0] == 1)
		return a;
	if (b > a)
		return nul;

	start = a.size() - b.size();
	
	while (x < b)
	{
		x.clear();

		for (i = start; i < a.size(); i++)
			x.push_back(a[i]);

		start--;
	}	

	d = Bins(x, b);
	ost = x - (b * d);
	rez.push_back(d[0]);

	for (i = start; i >= 0; i--)
	{
		x.clear();
		if (ost.size() == 1 && ost[0] == 0)
			x.push_back(a[i]);
		else
		{
			x.push_back(a[i]);
			for (j = 0; j < ost.size(); j++)
				x.push_back(ost[j]);
		}

		d = Bins(x, b);
		ost = x - (b * d);
		rez.push_back(d[0]);
	}

	i = 0;
	vll ans(rez.size());
	for (j = rez.size() - 1; j >= 0; j--)
	{
		ans[i] = rez[j];
		i++;
	}

	return ans;
}

vll mod(vll a, vll b)
{
	vll nul(1);

	if (b > a)
		return a;
	if (a == b)
		return nul;

	vll x(1);
	vll d;
	vll rez;
	vll ost(1);
	long long i = 0, j = 0, start;

	if (b.size() == 1 && b[0] == 1)
		return a;
	if (b > a)
		return nul;

	start = a.size() - b.size();

	while (x < b)
	{
		x.clear();

		for (i = start; i < a.size(); i++)
			x.push_back(a[i]);

		start--;
	}

	d = Bins(x, b);
	ost = x - (b * d);

	for (i = start; i >= 0; i--)
	{
		x.clear();
		if (ost.size() == 1 && ost[0] == 0)
			x.push_back(a[i]);
		else
		{
			x.push_back(a[i]);
			for (j = 0; j < ost.size(); j++)
				x.push_back(ost[j]);
		}

		d = Bins(x, b);
		ost = x - (b * d);
	}

	return ost;
}

vll operator +(vll a, vll b)
{
	vll nul(1);
	nul[0] = 0;
	long long i;

	if (a >= nul && b >= nul)
		return add(a, b);

	if (a < nul && b >= nul)
	{	
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;

		return sub(b, a);
	}

	if (a >= nul && b < nul)
	{
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		return sub(a, b);
	}

	if (a < nul && b < nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		vll rez = add(a, b);
		for (i = rez.size() - 1; i >= 0; i--)
			rez[i] *= -1;

		return rez;
	}
}

vll operator -(vll a, vll b)
{
	vll nul(1);
	nul[0] = 0;
	long long i;

	//cout << "a " << PrintLong(a) << endl;
	//cout << "b " << PrintLong(b) << endl;
	//cout << int(a >= nul) << endl << int(b >= nul);

	if (a >= nul && b >= nul)
		return sub(a, b);

	if (a < nul && b >= nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;

		vll rez = add(a, b);
		for (i = rez.size() - 1; i >= 0; i--)
			rez[i] *= -1;

		return rez;
	}

	if (a >= nul && b < nul)
	{
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		//cout << "b " << PrintLong(b) << endl;

		return add(a, b);
	}

	if (a < nul && b < nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		return sub(b, a);
	}

	return nul;
}

vll operator *(vll a, vll b)
{
	vll nul(1), x;
	nul[0] = 0;
	long long i;

	if (a >= nul && b >= nul)
		return mult(a, b);

	if (a < nul && b >= nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;

		x = mult(a, b);
		for (i = x.size() - 1; i >= 0; i--)
			x[i] *= -1;

		return x;
	}

	if (a >= nul && b < nul)
	{
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		x = mult(a, b);
		for (i = x.size() - 1; i >= 0; i--)
			x[i] *= -1;

		return x;
	}

	if (a < nul && b < nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		return mult(a, b);
	}
}

vll operator /(vll a, vll b)
{
	vll nul(1), x;
	nul[0] = 0;
	long long i;

	if (a >= nul && b >= nul)
		return div(a, b);

	if (a < nul && b >= nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;

		x = div(a, b);
		for (i = x.size() - 1; i >= 0; i--)
			x[i] *= -1;

		return x;
	}

	if (a >= nul && b < nul)
	{
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		x = div(a, b);
		for (i = x.size() - 1; i >= 0; i--)
			x[i] *= -1;

		return x;
	}

	if (a < nul && b < nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;
		for (i = b.size() - 1; i >= 0; i--)
			b[i] *= -1;

		return div(a, b);
	}
}

vll operator %(vll a, vll b)
{
	vll nul(1), x;
	nul[0] = 0;
	long long i;

	if (a >= nul)
	{
		if (b < nul)
			for (i = b.size() - 1; i >= 0; i--)
				b[i] *= -1;

		return mod(a, b);
	}

	if (a < nul)
	{
		for (i = a.size() - 1; i >= 0; i--)
			a[i] *= -1;

		if (b < nul)
			for (i = b.size() - 1; i >= 0; i--)
				b[i] *= -1;

		x = mod(a, b);
		for (i = x.size() - 1; i >= 0; i--)
			x[i] *= -1;

		return x;
	}
}

//vll operator %(vll a, vll b)
//{
//	vll nul(1);
//	
//	if (b > a)
//		return a;
//	if (a == b)
//		return nul;
//
//	return (a - ((a / b) * b));
//}
