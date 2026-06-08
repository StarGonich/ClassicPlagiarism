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
#include <cassert>

#define int long long
using namespace std;
mt19937 rng(58);

map<pair<int, int>, int> mp;

int go(int x, int cnt) {
	if (cnt == 0) {
		if (x == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (x == 0) {
		return 0;
	}
	if (mp.count({ x, cnt })) {
		return mp[{x, cnt}];
	}
	mp[{x, cnt}] = 0;
	for (int i = 1; i * i <= x; i++) {
		mp[{x, cnt}] = go(x - i * i, cnt - 1);
		if (mp[{x, cnt}] == 1) {
			break;
		}
	}
	return mp[{x, cnt}];
}

void solve() {
	mp[{0, 0}] = 1;
	int n;
	cin >> n;
	int d = -1;
	for (int i = 200; i < 250; i++) {
		int x = i * i;
		if (go(x, n) == 1) {
			d = i;
			break;
		}
	}

	vector<int> ans;
	int e = d * d;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j * j <= e; j++) {
			if (mp[{e - j * j, n - i - 1}] == 1) {
				e -= j * j;
				ans.push_back(j);
				break;
			}
		}
	}

	ans.push_back(d);
	int res = 0;
	for (int i = 0; i < n + 1; i++) {
		if (i != n) {
			res += ans[i] * ans[i];
		}
		cout << ans[i] << ' ';
	}
	assert(res == ans[n] * ans[n]);
	cout << '\n';
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