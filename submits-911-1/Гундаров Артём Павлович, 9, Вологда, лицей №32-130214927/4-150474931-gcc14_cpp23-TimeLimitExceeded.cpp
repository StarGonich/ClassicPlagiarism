#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    ll n, k;
    cin >> n >> k;

    vector<ll> del;

    for (int i = 1; 2 * i <= n; i++) {
        if (n % i == 0) del.push_back(i);
    }
    del.push_back(n);

    ll best = 0;
    ll lcmm = 1e18;

    for (auto d : del) {
        if (n + d > n + k) continue;
        ll lc = lcm(n, n + d);
        if (lc < lcmm) {
            lcmm = lc;
            best = n + d;
        }
    }

    cout << best;

    return 0;
}
