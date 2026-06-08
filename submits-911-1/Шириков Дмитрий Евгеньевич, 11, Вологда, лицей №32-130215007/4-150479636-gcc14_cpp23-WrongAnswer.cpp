#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
signed main() {
    ll n, k;
    cin >> n >> k;
    if (n + k >= 2 * n) {
        cout << 2 * n;
        return 0;
    }
    ll ans = 1e18, x  = 0;
    for (ll i = n + 1; i <= n + min(100000LL, k); i++) {
        ll t = (n * i) / __gcd(n, i);
        if (ans > t) {
            ans = t;
            x = i;
        }
    }
    cout << x;
    return 0;
}
