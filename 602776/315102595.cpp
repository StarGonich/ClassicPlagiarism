
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main()
{
    ld a, b, p;
    ld c, d, q;
    cin >> a >> b >> p;
    cin >> c >> d >> q;
    
    if (a == c && b == d && q != p ||
        a == c && q == p && b != d ||
        q == p && b == d && a != c)
    {
        cout << "Contradiction";
        return 0;
    }

    if (b * c - a * d == 0 || a / c == b / d && a / c == p / q)
    {
        cout << "Ambiguity";
        return 0;
    }


    ld zn = b * c - a * d;
    ld y = (p * c - a * q) / zn;
    ld x;
    if (a != 0)
        x = (p - b * y) / a;
    else
        x = (q - d * y) / c;
    if (y < 0 || x < 0)
    {
        cout << "Not positive";
        return 0;
    }
    cout << "Success\n";
    cout << x * 100 << ' ' << y * 100;
}

