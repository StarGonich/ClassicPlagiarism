#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1";
        return 0;
    }
    if (n == 2) {
        cout << "3\n1 2";
        return 0;
    }
    vector<ll> dp(31, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 6;
    for (int i = 4; i < 31; i++) {
        dp[i] = dp[i - 1] * 2;
    }

    cout << dp[n] << '\n';
    for (int i = 1; i < n; i++) {
        cout << dp[i] << " ";
        if (i == 2 && n >= 3) cout << "3 ";
    }

    return 0;
}
