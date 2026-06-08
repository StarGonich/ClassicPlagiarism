//#include <udacha$$$>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;
using vll = vector <ll>;
using vpll = vector <pll>;
using vvll = vector <vll>;

void solve();


int main()
{
    int t = 1; //cin >> t;
    while (t--)
        solve();
}

void solve()
{
    long double a, b, c, d, p, q;
    cin >> a >> b >> p >> c >> d >> q;
    cout << fixed << setprecision(8);
    long double x1, x2;
    if (a * d - b * c == 0)
    {
        if (a * q - c * p == 0)
        {
            cout << "Ambiguity\n";
        }
        else
        {
            cout << "Contradiction\n";
        }
        return;

    }
    if (a > 0)
    {
        x2 = (a * q - c * p) / (a * d - b * c);
        x1 = (p - x2 * b) / a;
        
    }
    else
    {
        x2 = (c * p - a * q) / (b * c - a * d);
        x1 = (q - d * x2) / c;
    }
    if (x1 <= 0 || x2 <= 0)
    {
        cout << "Not positive\n";
        return;
    }
    cout << "Success\n" << x1 * 100 << " " << x2 * 100;
}
