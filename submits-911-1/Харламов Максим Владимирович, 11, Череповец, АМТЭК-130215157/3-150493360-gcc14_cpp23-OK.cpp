#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1].second - a[i - 1].first;
    }
    a.push_back({INF, INF + 1});
    int j = 0;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        while (a[j].first < a[i].first + 3600) {
            if (pref[j + 1] - pref[i] > t) {
                    j++;
                    break;
            }
            j++;
        }
        j--;
        int time = 0;
        if (a[j].second <= a[i].first + 3600) {
            time += pref[j + 1] - pref[i];
            if (time > t) {
                int d = time - t - 1 + a[i].first + 3600 - a[j].second;
                ans = min(ans, max(0ll, a[i].first - d));
            }
        }
        else {
            time += pref[j] - pref[i];
            time += a[i].first + 3600 - a[j].first;
            if (time > t) {
                int d = time - t - 1;
                ans = min(ans, max(0ll, a[i].first - d));
            }
        }
    }
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}
