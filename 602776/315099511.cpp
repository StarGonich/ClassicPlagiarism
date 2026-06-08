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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<pair<int, int>> s;
	int e = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] + 1 != a[i]) {
			if (a[i - 1] != i - 1) {
				s.emplace_back(e, i - 1);
			}
			e = i;
		}
	}
	if (a[n - 1] != n - 1) {
		s.emplace_back(e, n - 1);
	}

	if (s.size() == 2) {
		cout << s[0].first + 1 << ' ' << s[0].second - s[0].first + 1 << '\n';
		cout << s[1].first + 1 << ' ' << s[1].second - s[1].first + 1 << '\n';
	}
	else {
		cout << -1 << '\n';
	}
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