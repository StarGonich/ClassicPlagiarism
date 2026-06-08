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
    vpll seg;
    ll n;
    cin >> n;
    vll perm(n); for (int i = 0; i < n; ++i) cin >> perm[i];
    ll st = 0, len = 1;
    for (int i = 1; i < n; ++i)
    {
        if (perm[i] - perm[i - 1] == 1)
        {
            ++len;
        }
        else
        {
            seg.push_back({ st, len });
            st = i; len = 1;
        }
    }
    seg.push_back({ st, len});
    if (seg.size() != 3)
    {
        cout << "-1\n";
        return;
    }
    ll a, b, c;
    a = perm[seg[0].first];
    b = perm[seg[1].first];
    c = perm[seg[2].first];
    if (a < b && b > c)
    {
        cout << seg[1].first + 1 << " " << seg[1].second << "\n";
        cout << seg[2].first + 1 << " " << seg[2].second << "\n";
    }
    else if (a > b && b < c)
    {
        cout << seg[0].first + 1 << " " << seg[0].second << "\n";
        cout << seg[1].first + 1 << " " << seg[1].second << "\n";
    }
    else
    {
        cout << seg[0].first + 1 << " " << seg[0].second << "\n";
        cout << seg[2].first + 1 << " " << seg[2].second << "\n";
    }
}
