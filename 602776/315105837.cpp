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
    ll n; cin >> n; vpll v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first;
    for (int i = 0; i < n; ++i) cin >> v[i].second;
    ll k;
    cin >> k;
    --k;
    ll left = v[k].first - v[k].second, right = v[k].first + v[k].second;
    ll ans = 1;
    int u1 = k - 1, u2 = k + 1;
    while (u1 > -1 && u2 < n)
    {
        bool flag = 0;
        if (v[u2].first <= right)
        {
            ++ans;
            right = max(right, v[u2].first + v[u2].second);
            left = min(left, v[u2].first - v[u2].second);
           // cout << right << " " << left << "\n";
            ++u2;
            flag = 1;
        }
        if (v[u1].first >= left)
        {
            ++ans;
            right = max(right, v[u1].first + v[u1].second);
            left = min(left, v[u1].first - v[u1].second);
            //cout << right << " " << left << "\n";
            --u1;
            flag = 1;
        }
        if (!flag)
        {
            break;
        }

    }
    while (u1 > -1)
    {
        bool flag = 0;
        if (v[u1].first >= left)
        {
            ++ans;
            right = max(right, v[u1].first + v[u1].second);
            left = min(left, v[u1].first - v[u1].second);
            //cout << right << " " << left << "\n";
            --u1;
            flag = 1;
        }
        if (!flag)
        {
            break;
        }
    }
    while (u2 < n)
    {
        bool flag = 0;
        if (v[u2].first <= right)
        {
            ++ans;
            right = max(right, v[u2].first + v[u2].second);
            left = min(left, v[u2].first - v[u2].second);
            //cout << right << " " << left << "\n";
            ++u2;
            flag = 1;
        }
        if (!flag)
        {
            break;
        }
    }
    cout << ans;
}
