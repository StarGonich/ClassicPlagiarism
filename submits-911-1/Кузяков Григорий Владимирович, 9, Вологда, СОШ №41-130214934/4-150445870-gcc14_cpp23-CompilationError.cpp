#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;


void solve() {
    ll n, k;
    cin >> n >> k;
    ll f = n + k;
    vector<ll> del;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            del.push_back(i);
            del.push_back(n / i);
        }
    }
    sort(del.rbegin(), del.rend());
    ll mini = inf, ans = 2 * n;
    for (auto d : del) {
        if (n + d <= f) {
            cout << n + d;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;


void solve() {
    ll n, k;
    cin >> n >> k;
    ll f = n + k;
    vector<ll> del;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            del.push_back(i);
            del.push_back(n / i);
        }
    }
    sort(del.rbegin(), del.rend());
    ll mini = inf, ans = 2 * n;
    for (auto d : del) {
        if (n + d <= f) {
            cout << n + d;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}

