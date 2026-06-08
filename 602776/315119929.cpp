#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

long long const mod = 1e9 + 7;

long long bp(long long a, long long n) {
	long long res = 1;
	while (n) {
		if (n & 1) {
			res = (res*a) % mod;
		}
		n /= 2;
		a = (a*a) % mod;
	}
	return res;
}

long long get(long long x, long long n, vector<vector<long long> > & dp) {
	if (x == 1) {
		return (dp[n - 3][0] + dp[n - 3][1]) % mod;
	} else if (x == 2) {
		return (dp[n - 4][0] + dp[n - 4][1]) % mod;
	} else if (x == n - 1) {
		return (dp[n - 3][0] + dp[n - 3][1]) % mod;
	} else if (x == n - 2) {
		return (dp[n - 4][0] + dp[n - 4][1]) % mod;
	} else {
	   return ((dp[x - 2][0] + dp[x - 2][1])*(dp[n - x - 2][0] + dp[n - x - 2][1])) % mod;
	}
}

int main() {
	long long n;
	cin >> n;
	
	if (n == 1) {
		cout << 0;
		return 0;
	} else if (n == 2) {
		cout << 1;
		return 0;
	} else if (n == 3) {
		cout << 2;
		return 0;
	}
	
	vector<vector<long long> > dp(n + 1, vector<long long> (2, 0));
	dp[0][0] = 1;
	
	dp[1][0] = 1;
	dp[1][1] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][0];
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
	}
	
	long long ans = 0;
	
	for (int i = 1; i < n; i++) {
	//	cout << i << " " << get(i, n, dp) << endl;
		ans = (ans + get(i, n, dp)) % mod;
	}
	
	cout << ans;
	
	return 0;
}