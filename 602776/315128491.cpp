
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
    ll p = 0;
    ll x;
    ll cnt = 0;
    while (s < 1000 && cnt < 100)
    {
        cout << n << " R" << endl;
        cin >> x;
        if (x == 0)
        {
            s -= n;
            n = s / 10;
            p++;
        }
        else if (x == -1)
        {
            return 0;
        }
        else
        {
            s += n;
            n = s / 10;
            p = 0;
        }

        if (p == 3)
        {
            n = s;
        }
        else
            n = s / 10;
        cnt++;
    }
}
