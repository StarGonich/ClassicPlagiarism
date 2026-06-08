#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;


void solve() {
    ll n, t;
    cin >> n >> t;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        auto& [a, b] = v[i];
        cin >> a >> b;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].second - v[i].first >= t) {
            cout << v[i];
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

