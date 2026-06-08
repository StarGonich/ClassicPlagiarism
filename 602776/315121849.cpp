
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
    vector<ll> x(n), d(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
        d[x[i] - 1] = i;
    }
    
    vector<vector<ll>> v;
    vector<ll> cur;
    ll cnt = 0;
    bool tr = 0;
    for (int i = 0; i < n; i++)
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
            if (x[i] - i == x[i - 1] - (i - 1))
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
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    map<ll, vector<ll>> mapa;
    for (int i = 0; i < n; i++)
    {
        if (x[i] - i != 1)
            mapa[x[i] - i].emplace_back(i);
    }

    ll cnt = mapa.size();

    for (auto r : mapa)
    {
        vector<ll> mas = r.second;
        for (int j = 1; j < mas.size(); j++)
        {
            if (mas[j] - mas[j - 1] != 1)
                cnt = 1000000000;
        }
    }

    if (cnt != 2)
    {
        cout << -1;
        return 0;
    }

    auto it = mapa.begin();
    auto it1 = it;
    it1++;

    if(it->second.size() == 1 || it1->second.size() == 1)
    {
        cout << -1;
        return 0;
    }

    if (it->second[0] < it1->second[0])
    {
        cout << it->second[0] + 1 << ' ' << it->second.size() << endl;
        cout << it1->second[0] + 1 << ' ' << it1->second.size() << endl;
    }
    else
    {
        cout << it1->second[0] + 1 << ' ' << it1->second.size() << endl;
        cout << it->second[0] + 1 << ' ' << it->second.size() << endl;
    }
}

