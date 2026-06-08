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
	vector<tuple<int, int, int>> s;
	int e = 0;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] + 1 != a[i]) {
			s.emplace_back(a[e], e, i - 1);
			e = i;
		}
	}
	s.emplace_back(a[e], e, n - 1);
	vector<tuple<int, int, int>> s2 = s;
	sort(s2.begin(), s2.end());

	vector<pair<int, int>> ans;
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] != s[i]) {
			ans.emplace_back(get<1>(s[i]) + 1, get<2>(s[i]) - get<1>(s[i]) + 1);
		}
	}

	if (ans.size() == 2) {
		cout << ans[0].first << ' ' << ans[0].second << '\n';
		cout << ans[1].first << ' ' << ans[1].second << '\n';
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