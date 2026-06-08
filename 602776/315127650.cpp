
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

int main1()
{
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    
    vector<vector<ll>> v;
    vector<ll> cur;
    ll cnt = 0;
    bool tr = 0;
    for (ll i = 0; i < n; i++)
    {
        if (cur.empty())
        {
            cur.emplace_back(x[i]);
            if (x[i] - i != 1)
            {
                cnt++;
                tr = 1;
            }
            else
                tr = 0;
        }
        else
        {
            if (x[i] == x[i-1] + 1)
            {
                cur.emplace_back(x[i]);
            }
            else
            {
                if(tr)
                    v.emplace_back(cur);
                cur.clear();
                cur.emplace_back(x[i]);
                if (x[i] - i != 1)
                {
                    cnt++;
                    tr = 1;
                }
                else
                    tr = 0;
            }
        }
    }
    if(tr)
        v.emplace_back(cur);

    if (cnt != 2)
    {
        cout << -1; 
        return 0;
    }

    ll pos1 = find(x.begin(), x.end(), v[0][0]) - x.begin() + 1;
    ll pos2 = find(x.begin(), x.end(), v[1][0]) - x.begin() + 1;
    cout << pos1 << ' ' << v[0].size() << endl;
    cout << pos2 << ' ' << v[1].size();
    return 0;
}

int main()
{
    ll s = 210;
    ll n = s / 16;
    vector<ll> a;
    while (s < 1000)
    {
        cout << n << " R" << endl;
        ll x;
        cin >> x;
        if (x == 0)
        {
            s -= n;
            n = s / 16;
        }
        else
        {
            s += n;
            n = s / 16;
        }
        a.emplace_back(x);

        if (a.size() > 2 && a[a.size() - 1] == 0 && a[a.size() - 2] == 0 && a[a.size() - 3] == 0)
        {
            n = s;
        }
        else
            n = s / 16;
    }
}
