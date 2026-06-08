#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e9;


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
    for (int i = 0; i < n; ++i) {
        if (v[i].second - v[i].first > t) {
            cout << max(0 ,min((v[i].second - 3599), v[i].first));
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
            int ans = inf;
            if (prefSum[i + l + 1] - prefSum[i] > t) {
                cout << max(0, v[i + l].second - 3600);
                return;
            }
            if (v[i + l + 1].first - v[i].first < 3600) {
                if (prefSum[i + l] - prefSum[i] + 3599 + v[i].first - v[i + l + 1].first > t) {
                    int cl = -1; r = 3600 + v[i].first - v[i + l + 1].first;
                    while (cl + 1 < r) {
                        int m = (cl + r) / 2;
                        if ((prefSum[i + l] - prefSum[i]) + m > t) {
                            r = m;
                        } else {
                            cl = m;
                        }
                    }
                    cout << max(0, v[i + l + 1].first + cl - 3599);
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

