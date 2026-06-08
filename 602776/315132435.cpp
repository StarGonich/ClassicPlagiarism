//#pragma optimizate("O3,unroll-loops,no-stack-protector")
//#pragma target("sse4.2,bmi,bmi2,fma,popcnt,lzcnt,avx,avx2,abm")

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <valarray>
#include <set>
#include <unordered_set>
#include <ctime>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <iterator>
#include <chrono>
#include <random>
#include <functional>

#define ll long long
#define all(x) x.begin(),x.end()
#define mp make_pair
//#define double long double
#define lll __int128_t

using namespace std;

void solution()
{
	ll n, i, j, mod = 1e9 + 7, ans = 0;

	cin >> n;
	vector<vector<ll> > dp(2, vector<ll>(n));
	vector<ll> A(n + 1);

	dp[0][0] = 1;
	dp[1][0] = 1;
	for (i = 1; i < n; ++i) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
		dp[1][i] = (dp[0][i - 1]) % mod;
	}

	for (i = 0; i < n; ++i) {
		A[i + 1] = (dp[0][i] + dp[1][i]) % mod;
	}

	if (n == 1) {
		cout << "1\n";
		return;
	}
	if (n == 2) {
		cout << "2\n";
		return;
	}
	if (n == 3) {
		cout << "4\n";
		return;
	}
	//for (i = 0; i < 2; ++i) {
	//	for (j = 0; j < n; ++j) {
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//for (i = 0; i < n; ++i)
	//	cout << A[i] << ' ';
	//cout << '\n';
 	
	ans = 0;
	ans = (ans + A[n - 3]) % mod;
	ans = (ans + A[n - 3]) % mod;
	if (n > 4) {
		ans = (ans + A[n - 4]) % mod;
		ans = (ans + A[n - 4]) % mod;
	}
	else
		ans = (ans + 1) % mod;
	for (i = 2; i + 3 < n; ++i) {
		ans = (ans + (A[i - 1] * A[n - i - 1]) % mod) % mod;
	}

	cout << ans << '\n';
}

int32_t main()
{
	//ll M = 911382323, N = 972663749;
	//unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int t; cin >> t;
	//while (t--)
		solution();
	return 0;
}