#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> dp0(n + 1, 0);
    auto dp1 = dp0;
    dp0[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp0[i] = (dp0[i - 1] + dp1[i - 1]) % MOD;
        dp1[i] = dp0[i - 1];
    }

    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int a = (i == 0 ? 1 : (dp0[i - 1] + dp1[i - 1]) % MOD);
        int j = n - (i + 1) - 1;
        int b = (j == 0 ? 1 : (dp0[j - 1] + dp1[j - 1]) % MOD);
        ans = (ans + a * b % MOD) % MOD;
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q = 1;
    // cin >> Q;
    while (Q--) {
        solve();
    }
}
