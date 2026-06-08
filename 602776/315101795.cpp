#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
#include <queue>
#include <random>

#define int long long
using namespace std;
mt19937 rng(58);

const int MOD = 1'000'000'007;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(2));
	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 0; i < n; i++) {
		dp[i + 1][0] = (dp[i][1] + dp[i][0]) % MOD;
		dp[i + 1][1] = dp[i][0];
	}

	int ans = 0;

	for (int i = 0; i < n - 1; i++) {
		int ost1 = i;
		int ost2 = n - (i + 1) - 1;
		ans = (ans + dp[ost1][1] * dp[ost2][1] % MOD) % MOD;
	}

	cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}