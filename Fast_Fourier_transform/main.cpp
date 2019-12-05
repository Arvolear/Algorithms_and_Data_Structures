#include <iostream>
#include <cmath>
#include <complex>
#include <vector>

using namespace std;

const double PI = 3.1415926535;
const double epsilon = 0.000000001;

void extendToClosestPowerOfTwo(vector < complex < double > > &poly0, vector < complex < double > > &poly1)
{
    size_t size = 1;

    while (size < poly0.size() + poly1.size())
    {
        size <<= 1;
    }
        
    poly0.resize(size);
    poly1.resize(size);
}

vector < complex < double > > fourier(const vector < complex < double > > &poly, bool invert)
{
    if (poly.size() == 1)
    {
        return {{poly[0]}};
    }

    vector < complex < double > > polyEven;
    vector < complex < double > > polyOdd;
    
    for (size_t i = 0; i < poly.size(); i++)
    {
        if (i % 2 == 0)
        {
            polyEven.push_back(poly[i]);
        }
        else
        {
            polyOdd.push_back(poly[i]);
        }
    }

    vector < complex < double > > resEven = fourier(polyEven, invert);
    vector < complex < double > > resOdd = fourier(polyOdd, invert);

    vector < complex < double > > res(poly.size());
    
    double angle = 2 * PI / poly.size() * (invert ? -1 : 1);
    complex < double > tmpRoot(1, 0), root(cos(angle), sin(angle));

    for (size_t i = 0; i < poly.size() / 2; i++)
    {
        res[i] = resEven[i] + tmpRoot * resOdd[i];
        res[i + poly.size() / 2] = resEven[i] - tmpRoot * resOdd[i];

        if (invert)
        {
            res[i] /= 2;
            res[i + poly.size() / 2] /= 2;
        }

        tmpRoot *= root;
    }

    return res;
}

vector < double > multiply(const vector < double > &polynom0, const vector < double > &polynom1)
{
    vector < complex < double > > poly0;
    vector < complex < double > > poly1;

    for (size_t i = 0; i < polynom0.size(); i++)
    {
        poly0.push_back({polynom0[i], 0});
    }
    
    for (size_t i = 0; i < polynom1.size(); i++)
    {
        poly1.push_back({polynom1[i], 0});
    }
    
    extendToClosestPowerOfTwo(poly0, poly1);

    vector < complex < double > > numPoly0 = fourier(poly0, false);
    vector < complex < double > > numPoly1 = fourier(poly1, false);
    
    vector < complex < double > > res;

    for (size_t i = 0; i < numPoly0.size(); i++)
    {
        res.push_back(numPoly0[i] * numPoly1[i]);
    }
    
    res = fourier(res, true);

    vector < double > ans;

    for (size_t i = 0; i < res.size(); i++)
    {
        if (res[i].real() + epsilon > 0 && res[i].real() - epsilon < 0)
        {
            continue;
        }
        
        ans.push_back(res[i].real());
    }

    return ans;
}

void printPolynom(const vector < double > &polynom)
{
    for (size_t i = 0; i < polynom.size(); i++)
    {
        if (!polynom[i])
        {
            continue;
        }

        if (i == 0)
        {
            if (i == polynom.size() - 1)
            {
                cout << polynom[i];
            }
            else
            {
                cout << polynom[i] << " + ";
            }
        }
        else if (polynom[i] - epsilon < 1 && polynom[i] + epsilon > 1)
        {
            if (i == polynom.size() - 1)
            {
                cout << "x^" << i;
            }
            else
            {
                cout << "x^" << i << " + ";
            }
        }
        else
        {
            if (i == polynom.size() - 1)
            {
                cout << polynom[i] << "x^" << i;
            }
            else
            {
                cout << polynom[i] << "x^" << i << " + ";
            }
        }
    }

    cout << endl;
}

int main()
{
    vector < double > polynom0, polynom1;
    int power0, power1;

    cout << "\nPlease insert the power of the first polynomial:\n";
    cin >> power0;

    cout << "\nPlease insert " << power0 << " coefficients:\n";
    for (int i = 0; i < power0; i++)
    {
        int x;
        cin >> x;

        polynom0.push_back(x);
    }
    
    cout << "\nPlease insert the power of the second polynomial:\n";
    cin >> power1;

    cout << "\nPlease insert " << power1 << " coefficients:\n";
    for (int i = 0; i < power1; i++)
    {
        int x;
        cin >> x;

        polynom1.push_back(x);
    }

    vector < double > res = multiply(polynom0, polynom1);

    cout << "\nFirst polynomial:\n";
    printPolynom(polynom0);
    
    cout << "\nSecond polynomial:\n";
    printPolynom(polynom1);

    cout << "\nResult of multiplication:\n";
    printPolynom(res);

    return 0;
}
