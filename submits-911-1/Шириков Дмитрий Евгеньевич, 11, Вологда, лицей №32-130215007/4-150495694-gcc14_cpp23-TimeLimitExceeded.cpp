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
    ll ans1 = 1e18, x1  = 0;
    ll ans2 = 1e18, x2  = 0;
    for (ll i = n + k; i >= max(n + 1, ll(n + k - 1e6*4)); i--) {
        ll t = (n * i) / gcd(n, i);
        if (ans1 > t) {
            ans1 = t;
            x1 = i;
        }
    }
    ll fir = n + (n / 2);
    for (ll i = max(n + 1, fir - ll(1e6*4)); i < min(n + k, fir + ll(1e6*4)); i++) {
        ll t = (n * i) / gcd(n, i);
        if (ans2 > t) {
            ans2 = t;
            x2 = i;
        }
    }
    if (ans1 < ans2) cout << x1;
    else cout << x2;
    return 0;
}
