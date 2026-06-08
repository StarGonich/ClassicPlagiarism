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

void solve() {
	int n;
	cin >> n;
	cout << (n / 4) + (n / 5) + (n / 6) - 2 * (n / 20) - 2 * (n / 30) - 2 * (n / 12) + 3 * (n / 60) << '\n';
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