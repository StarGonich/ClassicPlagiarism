#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n);

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        int left = (i > 0 ? dp[i - 1] : 1);
        int right = (i < n - 2 ? dp[n - i - 3] : 1);
        // cout << i << " " << left << " " << right << endl;
        ans = (ans + 1LL * left * right) % MOD;
    }
    cout << ans << "\n";
}
