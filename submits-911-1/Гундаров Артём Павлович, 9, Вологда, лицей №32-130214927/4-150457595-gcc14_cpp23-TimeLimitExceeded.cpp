#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    ll n, k;
    cin >> n >> k;

    if (n + k >= 2 * n) {
        cout << 2 * n;
        return 0;
    }

    ll lcmm = 1e18;
    ll best = -1;

    for (int i = n + 1; i <= n + k; i++) {
        ll lc = n / gcd(n, i) * i;
        if (lc < lcmm) {
            lcmm = lc;
            best = i;
        }
    }

    cout << best;

    return 0;
}
