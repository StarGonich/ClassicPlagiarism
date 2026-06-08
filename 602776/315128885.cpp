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

int dx[] = {0, -1, 1, 0, 0};
int dy[] = { 0, 0, 0, -1, 1 };

void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	vector<pair<int, int>> res(500);

	for (int i = 0; i < (1 << n); i++) {
		vector<string> s2 = s;
		vector<pair<int, int>> ans;
		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1) == 1) {
				ans.emplace_back(0, j);
				for (int e = 0; e < 5; e++) {
					if (0 + dx[e] >= 0 && 0 + dx[e] < n && j + dy[e] >= 0 && j + dy[e] < n) {
						s2[0 + dx[e]][j + dy[e]] = (s2[0 + dx[e]][j + dy[e]] == 'w' ? 'b' : 'w');
					}
				}
			}
		}

		for (int j = 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (s2[j - 1][k] == 'w') {
					ans.emplace_back(j, k);
					for (int e = 0; e < 5; e++) {
						if (j + dx[e] >= 0 && j + dx[e] < n && k + dy[e] >= 0 && k + dy[e] < n) {
							s2[j + dx[e]][k + dy[e]] = (s2[j + dx[e]][k + dy[e]] == 'w' ? 'b' : 'w');
						}
					}
				}
			}
		}

		bool ok = 1;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (s2[j][k] != 'b') {
					ok = 0;
				}
			}
		}

		if (ok) {
			if (res.size() > ans.size()) {
				res = ans;
			}
		}
	}


	for (int i = 0; i < (1 << n); i++) {
		vector<string> s2 = s;
		vector<pair<int, int>> ans;
		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1) == 1) {
				ans.emplace_back(0, j);
				for (int e = 0; e < 5; e++) {
					if (0 + dx[e] >= 0 && 0 + dx[e] < n && j + dy[e] >= 0 && j + dy[e] < n) {
						s2[0 + dx[e]][j + dy[e]] = (s2[0 + dx[e]][j + dy[e]] == 'w' ? 'b' : 'w');
					}
				}
			}
		}

		for (int j = 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (s2[j - 1][k] == 'b') {
					ans.emplace_back(j, k);
					for (int e = 0; e < 5; e++) {
						if (j + dx[e] >= 0 && j + dx[e] < n && k + dy[e] >= 0 && k + dy[e] < n) {
							s2[j + dx[e]][k + dy[e]] = (s2[j + dx[e]][k + dy[e]] == 'w' ? 'b' : 'w');
						}
					}
				}
			}
		}

		bool ok = 1;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (s2[j][k] != 'w') {
					ok = 0;
				}
			}
		}

		if (ok) {
			if (res.size() > ans.size()) {
				res = ans;
			}
		}
	}

	if (res.size() < 500) {
		cout << res.size() << '\n';
		for (auto p : res) {
			cout << p.first + 1 << ' ' << p.second + 1 << '\n';
		}
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