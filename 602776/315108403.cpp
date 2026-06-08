
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

    set<ll> dif;
    for(int i = 0; i < n; i++)
    {
        if (x[i] - i != 1)
        {
            dif.emplace(x[i] - i);
        }
    }

    if (dif.size() != 2)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i] - i != 1)
        {
            cout << i + 1 << ' ';
            ll cnt = 0;
            ll razn = x[i] - i;
            while (i < n && x[i] - i == razn)
            {
                cnt++;
                i++;
            }
            i--;
            cout << cnt << endl;
        }
    }

}

