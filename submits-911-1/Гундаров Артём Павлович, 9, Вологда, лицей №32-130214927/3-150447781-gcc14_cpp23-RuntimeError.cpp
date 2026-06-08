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

    vector<int> pref(1e6 + 2, 0), rmas(1e6 + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        rmas[l]++;
        rmas[r]--;
    }
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
