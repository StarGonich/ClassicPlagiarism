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
    vector<int> prefSum(n + 1);
    prefSum[0] = 0;
    for (int i = 0; i < n; ++i) {
        prefSum[i + 1] = prefSum[i] + v[i].second - v[i].first;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].second - v[i].first >= t) {
            cout << v[i].first;
            return;
        } else {
            int l = -1, r = n - i + 1;
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (v[i + m].second - v[i].first > 3600) {
                    r = m;
                } else {
                    l = m;
                }
            }
            if (v[l + i + 1].first - v[i].first < 3600) {
                if (prefSum[l + 1] - prefSum[i] - v[l + i + 1].first + v[i].first + 3600 > t) {
                    cout << v[i].first;
                    return;
                }
            } else {
                if (prefSum[l + 1] - prefSum[i] > t) {
                    cout << v[i].first;
                    return;
                }
            }
        }
    }
    cout << -1;
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

