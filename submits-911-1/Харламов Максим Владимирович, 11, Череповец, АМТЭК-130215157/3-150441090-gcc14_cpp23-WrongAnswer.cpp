#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].second--;
    }
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i - 1].second - a[i - 1].first + 1;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (a[j].second <= a[i].second - 3600) j++;
        int time = 0;
        if (a[j].first <= a[i].second - 3600) {
            time += a[j].second - (a[i].second - 3600) + 1;
            time += p[i + 1] - p[j + 1];
        }
        else {
            time = p[i + 1] - p[j];
        }
        if (time > t) {
            int d = time - t - 1;
            cout << max(0ll, a[i].second - 3600 - d) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
