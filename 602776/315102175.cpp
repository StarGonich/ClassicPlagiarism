#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    int k;
    cin >> k;
    k--;

    int l = k, r = k;
    int dl = x[k], dr = x[k];
    while (l >= 0 || r < n) {
        bool changed = false;

        if (l >= 0 && x[l] >= dl) {
            dl = min(dl, x[l] - d[l]);
            dr = max(dr, x[l] + d[l]);
            l--;
            changed = true;
        }

        if (r < n && x[r] <= dr) {
            dl = min(dl, x[r] - d[r]);
            dr = max(dr, x[r] + d[r]);
            r++;
            changed = true;
        }

        if (!changed) break;
    }

    cout << r - l - 1 << '\n';
}
