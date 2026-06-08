
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

int main2() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];

    ll l1 = -1, r1 = -1, l2 = -1, r2 = -1;
    for (ll i = 0; i < n; i++)
    {
        if (l1 == -1 && x[i] != i + 1)
        {
            l1 = i;
            r1 = i;
            i++;
            while (i < n && x[i] == x[i - 1] + 1)
            {
                r1 = i;
                i++;
            }
        }

        if (i < n && l2 == -1 && x[i] != i + 1)
        {
            l2 = i;
            r2 = i;
            i++;
            while (i < n && x[i] == x[i - 1] + 1)
            {
                r2 = i;
                i++;
            }
        }

        if (i < n && x[i] != i + 1)
        {
            cout << -1;
            return 0;
        }
    }

    if (l1 == -1 || l2 == -1)
    {
        cout << -1;
        return 0;
    }

    cout << l1 + 1 << ' ' << r1 - l1 + 1 << '\n' << l2 + 1 << ' ' << r2 - l2 + 1;

}

int main()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << "1 1";
    }
    else if (n == 2)
    {
        cout << "3 4 5";
    }
    else
    {
        ll cnt = 2;
        ll last = 4;
        ll sum = 25;
        vector<ll> ans = { 3, 4 };
        while (cnt < n)
        {
            for (ll i = last + 1; i <= 1e9; i++)
            {
                ll nw = sum + i * i;
                ll sq = sqrt(nw);
                if (sq * sq == nw)
                {
                    cnt++;
                    sum = nw;
                    ans.emplace_back(i);
                    last = i;
                    break;
                }
            }
        }
        for (auto i : ans)
            cout << i << ' ';
        cout << sqrt(sum);
    }
}
