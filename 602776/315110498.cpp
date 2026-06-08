#define _USE_MATH_DEFINES
#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

#define ll long long
#define sortt(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())

struct fenwick {
	vector<int> t;
	int n;

	fenwick(int n_) : n(n_) {
		t.assign(n, 0);
	}

	int get(int i) {
		int sum = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1) sum += t[i];
		return sum;
	}

	void add(int i, int dif) {
		for (; i < n; i = i | (i + 1)) t[i] += dif;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int M = 1e9 + 7;

int dp[2][2][1000010];

void solve() {
	int n;
	cin >> n;
	dp[0][0][0] = 1;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		dp[1][0][i] = (dp[0][0][i - 1]) % M;
		dp[1][1][i] = (dp[0][1][i - 1] + dp[1][0][i - 1]) % M;
		dp[0][0][i] = (dp[0][0][i - 1] + dp[1][0][i - 1]) % M;
		dp[0][1][i] = (dp[1][1][i - 1] + dp[0][1][i - 1]) % M;
	}
	cout << (dp[0][1][n] + dp[1][1][n]) % M << endl;
}

int main()
{
	cout.tie(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	solve();
}
