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

const int M = 1e9 + 7;
const int W = 10000;
int dp[1000][W + 1];

void solve() {
	int n;
	cin >> n;
	dp[0][0] = -1;

	for (int i = 0; i < n; i++) {
		for (int j = W; j >= 0; j--) {
			for (int add = 1; ; add++) {
				if (add * add * i > W) break;
				if (j - add * add < 0) break;
				if (dp[i][j - add * add] == 0) continue;
				dp[i + 1][j] = add;
			}
		}
	}

	vector<int> ans;

	for (int sq = 1; ; sq++) {
		if (sq * sq > W) break;
		if (!dp[n][sq * sq]) continue;

		ans.push_back(sq);

		int nn = n;
		int w = sq *sq;
		while (w > 0) {
			ans.push_back(dp[nn][w]);
			w -= dp[nn][w] * dp[nn][w];
			nn--;
		}

		rev(ans);
		for (int i : ans) cout << i << ' ';

		return;
	}
	cout << -1 << endl;
}

int main()
{
	cout.tie(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	solve();
}
