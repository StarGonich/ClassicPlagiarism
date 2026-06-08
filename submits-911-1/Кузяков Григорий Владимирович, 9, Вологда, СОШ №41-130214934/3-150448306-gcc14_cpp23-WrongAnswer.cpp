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
        int l = -1, r = n - i + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (v[i + m].second - v[i].first >= t) {
                r = m;
            } else {
                l = m;
            }
        }
        if (l != -1) {
            cout << v[i].first;
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

