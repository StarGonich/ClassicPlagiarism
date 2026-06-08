#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <memory>
#include <stack>
using namespace std;
using ll = long long;
using ld = long double;
#define debug(x) std::cerr << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << '\n';
const ll INF = 4e18;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
const ll mod = 1e9 + 7;
void solve(){
	ll n;
	cin >> n;
	vector<vector<ll>> dp(n + 1, vector<ll>(2,0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[0][0] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][0] %= mod;
		dp[i][1] += (dp[i - 1][0] + 1);
		dp[i][1] %= mod;
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll len_left = max(0LL, (ll)i - 2);
		ll len_right = max(0LL, n - (i + 1) - 1);
		ll tt1 = dp[len_left][0] % mod + dp[len_left][1] % mod;
		ll tt2 = dp[len_right][0] % mod + dp[len_right][1] % mod;
		ans = ans + (((dp[len_left][0] % mod + dp[len_left][1] % mod)) % mod % mod * (((dp[len_right][0] % mod  + dp[len_right][1] % mod)) % mod) % mod) % mod;
		ans %= mod;
	}
	cout << ans%mod;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}