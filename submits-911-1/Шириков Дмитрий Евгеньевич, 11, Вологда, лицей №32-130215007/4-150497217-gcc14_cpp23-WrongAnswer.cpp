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
    for (ll i = n + k; i >= max(n + 1, ll(n + k - 1e6)); i--) {
        ll t = (n * i) / gcd(n, i);
        if (ans1 > t) {
            ans1 = t;
            x1 = i;
        }
    }
    ll fir = n + (n / 2);
    for (ll i = max(n + 1, fir - ll(1e6)); i < min(n + k, fir + ll(1e6)); i++) {
        ll t = (n * i) / gcd(n, i);
        if (ans2 > t) {
            ans2 = t;
            x2 = i;
        }
    }
    fir = n + (n / 5);
    ll ans3 = 1e18, x3 = 0;
    for (ll i = max(n + 1, fir - ll(1e6)); i < min(n + k, fir + ll(1e6)); i++) {
        ll t = (n * i) / gcd(n, i);
        if (ans3 > t) {
            ans3 = t;
            x3 = i;
        }
    }
    vector<ll> a = {ans1, ans2, ans3};
    ll mn = *min_element(a.begin(), a.end());
    if (ans1 == mn) {
        cout << x1;
        return 0;
    }
    if (ans2 == mn) {
        cout << x2;
        return 0;
    }
    if (ans3 == mn) {
        cout << x3;
        return 0;
    }
}
