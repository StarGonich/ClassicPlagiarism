#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    return gcd(x % y, y);
}
signed main() {
    ll n, k;
    cin >> n >> k;
    if (n + k >= 2 * n) {
        cout << 2 * n;
        return 0;
    }
    ll ans = 1e18, x = 0;
    for (int i = 1; i < 5; i++) {
        ll fir = n + (n / i);
        ll cur_ans = 1e18, cur_x = 0;
        for (ll i = max(n + 1, fir - ll(1e6)); i < min(n + k, fir + ll(1e6)); i++) {
            ll t = (n * i) / gcd(n, i);
            if (cur_ans > t) {
                cur_ans = t;
                cur_x = i;
            }
        }
        if (ans > cur_ans) {
            ans = cur_ans;
            x = cur_x;
        }
    }
    cout << x;
}
