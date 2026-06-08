#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    int T;
    cin >> T;
    if (T == 3600) {
        cout << -1;
        return 0;
    }
    vector<int> t1(n);
    vector<int> t2(n);
    vector<int> pref(n + 1, 0);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        cin >> t1[i] >> t2[i];
        pref[i + 1] = pref[i] + t2[i] - t1[i];
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        r = max(r, i);
        while (r + 1 < n && t2[r + 1] - t1[i] <= 3600) {
            r++;
        }
        int sum = pref[r + 1] - pref[i];
        if (r + 1 < n && t1[r + 1] - t1[i] < 3600) {
            sum += t1[i] + 3600 - t1[r + 1];
        }
        if (sum > T) {
            ans = min(ans, t1[i]);
            int l = 0, r1 = 0;
            for (int j = max(t1[i] - 3600, 0); j <= t1[i]; j++) {
                while (l < n && t2[l] <= j) {
                    l++;
                }
                while (r1 + 1 < n && t1[r1 + 1] <= j + 3600) {
                    r1++;
                }
                sum = 0;
                if (l < n && t2[l] <= j + 3600 && t2[l] > j) {
                    sum += min(t2[l] - t1[l], t2[l] - j);
                }
                if (r1 < n && t1[r1] <= j + 3600) {
                    sum += min(t2[r1] - t1[r1], j + 3600 - t1[r1]);
                }
                sum += pref[r1] - pref[min(n, l + 1)];
                if (sum > T) {
                    ans = min(ans, j);
                    break;
                }
            }
            break;
        }
    }
    if (ans == INF) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}
