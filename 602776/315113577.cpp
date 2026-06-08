#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 engine(time(nullptr));

const int INF = 2 * 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-7;

void solve();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	/*cin >> t;*/
	t = 1;

	while (t--) {
		solve();
	}
}

int used[1000010][2];
int dp[1000010][2];
int n;

int rec(int x, int was) {
	if (x >= n) {
		return was;
	}
	if (used[x][was]) {
		return dp[x][was];
	}
	used[x][was] = 1;

	if (was) {
		int v1 = rec(x + 1, was);
		int v2 = rec(x + 2, was);
		return dp[x][was] = (v1 + v2) % MOD;
	}
	else {
		int v1 = rec(x + 1, was);
		int v2 = 0;
		if (x + 1 < n) {
			v2 = rec(x + 3, 1);
		}
		int v3 = rec(x + 2, was);
		return dp[x][was] = ((v1 + v2) % MOD + v3) % MOD;

	}
}

void solve() {
	cin >> n;

	cout << rec(0, 0);
}
