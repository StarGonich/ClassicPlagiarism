#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <bitset>
#include <random>
#include <ctime>

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;

mt19937_64 rng(time(NULL));

void solve();
signed main() {
	ios::sync_with_stdio(0); cin.tie();
	//freopen("out.txt", "w", stdout);
	int c = 1;
	//cin >> c;
	while (c--) solve();
}

ll dp[1000001];

void solve() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "0\n";
		return;
	}

	dp[0] = 1;
	dp[1] = 2;


	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}

	ll ans = 0;

	for (int i = 1; i < n; ++i) {
		ll lCnt = max(0, i - 2);
		ll rCnt = max(0, n - i - 2);

		ans += dp[lCnt] * dp[rCnt];
		ans %= mod;
	}

	cout << ans;
}