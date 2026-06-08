#include <bits/stdc++.h>

using namespace std;

struct event {
    long long l, r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n, m;
    cin >> k >> n >> m;
    vector<pair<int, int> > sum(k);
    for (int i = 0; i < k; ++i) {
        int b = 0;
        vector<vector<int> > a(n + 2, vector<int> (m + 2, -1));
        for (int j = 1; j <= n; ++j) {
            for (int h = 1; h <= m; ++h) {
                cin >> a[j][h];
                if (a[j][h] == 1) b++;
            }
        }
        for (int j = 1; j <= n; ++j) {
            for (int h = 1; h <= m; ++h) {
                int cnt = 0;
                if (a[j][h] == 1) {
                    if (a[j - 1][h] == 1) cnt++;
                    if (a[j + 1][h] == 1) cnt++;
                    if (a[j][h - 1] == 1) cnt++;
                    if (a[j][h + 1] == 1) cnt++;
                    if (cnt < 2 || cnt > 3) b--;
                } else {
                    if (a[j - 1][h] == 1) cnt++;
                    if (a[j + 1][h] == 1) cnt++;
                    if (a[j][h - 1] == 1) cnt++;
                    if (a[j][h + 1] == 1) cnt++;
                    if (cnt == 3) b++;
                }
            }
        }
        sum[i].first = b;
        sum[i].second = -(i + 1);
    }
    sort(sum.rbegin(), sum.rend());
    for (int i = 0; i < k; ++i) {
        cout << -sum[i].second << " ";
    }
    return 0;
}
