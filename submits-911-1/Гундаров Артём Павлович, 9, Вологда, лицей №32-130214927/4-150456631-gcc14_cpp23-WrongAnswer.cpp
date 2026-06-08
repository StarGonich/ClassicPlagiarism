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

    if (n == 1) {
        cout << "2";
        return 0;
    }

    ll nn = n;

    vector<ll> del;
    for (ll i = 2; i * i <= nn; i++) {
        while (nn % i == 0) {
            del.push_back(i);
            nn /= i;
        }
    }
    if (nn > 1) del.push_back(nn);

    del.erase(unique(del.begin(), del.end()), del.end());

    ll lcmm = 1e18;
    ll best = -1;

    for (auto d : del) {
        for (ll i = n + d; i <= n + k; i += d) {
            ll lc = n / gcd(n, i) * i;
            if (lc < lcmm) {
                lcmm = lc;
                best = i;
            }
            //cout << n << " " << i << " " << lc << '\n';
        }
    }

    cout << best;

    return 0;
}
