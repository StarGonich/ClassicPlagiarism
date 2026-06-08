#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll ans = -1, nk = 1e18;
    for(ll i = n + 1; i <= n + k; i++) {
        if(lcm(n, i) < nk) {
            ans = i; nk = lcm(n, i);
        }
    }
    cout << ans;
    return 0;
}
