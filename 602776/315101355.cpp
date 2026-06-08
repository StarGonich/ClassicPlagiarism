#include <bits/stdc++.h>

#define fi first
#define se second
#define all(x) x.begin(), x.end()

#define int ll

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

void solve() {
    int n; cin >> n;
    vi x(n), d(n);
    for (auto &y : x)
        cin >> y;
    for (auto &y : d)
        cin >> y;

    int k; cin >> k;
    k--;

    int a = x[k] - d[k];
    int b = x[k] + d[k];
    int i = k - 1, j = k + 1;

    int ans = 1;
    while (true) {
        int cnt = 0;

        while (i >= 0 && a <= x[i]) {
            a = min(a, x[i] - d[i]);
            b = max(b, x[i] + d[i]);
            ans++;
            i--;
            cnt++;
        }

        while (j < n && b >= x[j]) {
            a = min(a, x[j] - d[j]);
            b = max(b, x[j] + d[j]);
            ans++;
            j++;
            cnt++;
        }
        
        while (i >= 0 && a <= x[i]) {
            a = min(a, x[i] - d[i]);
            b = max(b, x[i] + d[i]);
            ans++;
            i--;
            cnt++;
        }

        if (cnt == 0)
            break;
    }

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t --> 0) {
        solve();
        cout << '\n';
    }

    return 0;
}
