#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> lol(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        lol[i] = {a, b};
    }
    for (int i = 0; i <= 1500000 - 3600; ++i) {
        ll cnt = 0;
        for (int j = 0; j < n; j++) {
            if (lol[j].first >= i + 3600) {
                break;
            }
            if (max(i, lol[j].first) < min(i + 3600, lol[j].second)) {
                cnt += (min(i + 3600, lol[j].second) - max(i, lol[j].first));
            }
        }
        if (cnt > t) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
