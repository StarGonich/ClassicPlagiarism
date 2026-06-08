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

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    // без соседей
    vi dp(n + 1);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;

    int ans = 0;
    for (int i = 1; i <= n-1; i++) {
        int a = max(0ll, i-2);
        int b = max(0ll, n-(i+2));

        ans += dp[a] * dp[b] % MOD;
        ans %= MOD;
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
