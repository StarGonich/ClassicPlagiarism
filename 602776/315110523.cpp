#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <ios>
#include <iomanip>
#include <cmath>

#define int long long
#define ll long long

using namespace std;

ll fastPow(int a, int p, int m) {
	if (p == 0) return 1;
	if (p == 1) return a % m;

	if (p % 2 == 0) {
		ll res = fastPow(a, p / 2, m);
		return (res * res) % m;
	}
	else {
		ll res = fastPow(a, p / 2, m);
		return (((res * res) % m) * a) % m;
	}
}

void solve() {
	int n; cin >> n;

	int mod = 1e9 + 7;

	vector<vector<int>> dp(n, vector<int> (4));

	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 0; i < n - 1; i++) {
		dp[i + 1][0] = (dp[i][0] + dp[i][1]) % mod;
		dp[i + 1][1] = dp[i][0] % mod;
		dp[i + 1][2] = (dp[i][2] + dp[i][3]) % mod;
		dp[i + 1][3] = (dp[i][2] + dp[i][1]) % mod;
	}

	cout << (dp[n-1][2] + dp[n-1][3]) % mod;
}

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
