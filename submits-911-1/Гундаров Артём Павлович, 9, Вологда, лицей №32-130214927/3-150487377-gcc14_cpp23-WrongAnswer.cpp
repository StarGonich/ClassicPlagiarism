#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    int n, t;
    cin >> n >> t;

    bool v = 0;

    vector<int> pref(1e6 + 2, 0), rmas(1e6 + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (r > 1e6 + 1 && !v) {
            cout << "-1";
            v = 1;
        }
        if (l < 1e6 + 2) rmas[l]++;
        if (r < 1e6 + 2) rmas[r]--;
    }
    if (v) return 0;
    int delta = rmas[0];
    for (int i = 1; i < 1e6 + 2; i++) {
        pref[i] = pref[i - 1] + delta;
        delta += rmas[i];
    }

    for (int i = 0; i < 1e6 + 2 - 3600; i++) {
        if (pref[i + 3600] - pref[i] > t) {
            cout << i;
            return 0;
        }
    }
    cout << "-1";

    return 0;
}
