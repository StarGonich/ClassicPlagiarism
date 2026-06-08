
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
    ll n;
    cin >> n;
    vector<ll> x(n), p, v;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    p = x;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        if (x[i] != p[i])
            v.emplace_back(i);
    }

    ll cnt = 0;

    ll ind;

    for (int i = 1; i < v.size(); i++)
    {
        if (x[v[i]] - x[v[i - 1]] != 1)
        {
            cnt++;
            ind = i;
        }
    }

    if (cnt != 1)
        cout << -1;
    else
    {
        cout << v[0] + 1 << ' ' << v[ind - 1] - v[0] + 1 << endl;
        cout << v[ind] + 1 << ' ' << v.back() - v[ind] + 1;
    }

}

