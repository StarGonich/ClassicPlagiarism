
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
    vector<ll> x(n), d(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    for (ll i = 0; i < n; i++)
        cin >> d[i];
    ll k;
    cin >> k;

    ll ans = 1;

    ll l = k - 1, r = k - 1;
    ll ras_l = x[l] - d[l], ras_r = x[l] + d[l];
    while (l > 0 || r < n - 1)
    {
        bool tr = 0;
        if (l > 0 && x[l - 1] >= ras_l)
        {
            ans++;
            l--;
            ras_l = min(ras_l, x[l] - d[l]);
            ras_r = max(ras_r, x[l] + d[l]);
            tr = 1;
        }

        if (r < n - 1 && x[r + 1] <= ras_r)
        {
            ans++;
            r++;
            ras_l = min(ras_l, x[r] - d[r]);
            ras_r = max(ras_r, x[r] + d[r]);
            tr = 1;
        }

        if (!tr)
            break;
    }

    cout << ans;

}

