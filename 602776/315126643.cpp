#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    const long long mod = 1e9 + 7;

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> dp(n, 0);

    vector<long long> pref(n, 0);
    for (long long i = 2, j = 1; i < n; i++, j++) pref[i] = pref[i - 1] + j;

    vector<long long> suff(n, 0);
    for (long long i = n - 1, j = 0; i >= 0; i--, j++) suff[i] = pref[j];

    for (int i = 0; i < n - 1; i++) {
        long long l;
        if (i <= 1) l = 0;
        else l = pref[i] - (pref[i - 1] - pref[i - 2]);
        l %= mod;

        long long r;
        if (i <= n - 4) r = suff[i + 1] - (suff[i + 2] - suff[i + 3]);
        else r = 0;
        r %= mod;

        if (i != 0) dp[i] = (dp[i - 1] + 1) % mod;
        else dp[i] = 1;
        dp[i] = (dp[i] + l) % mod;
        dp[i] = (dp[i] + r) % mod;
        dp[i] = (dp[i] + l * r) % mod;
    }
    cout << dp[n - 2] << '\n';
}
