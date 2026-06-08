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

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int x = 0;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'b') {
				x ^= (1ll << j);
			}
		}
		a[i] = x;
	}

	vector<int> c(1 << n);
	for (int i = 1; i < (1 << n); i++) {
		c[i] = c[i >> 1] + (i & 1);
	}

	vector<int> get(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1) == 1) {
				if (j - 1 >= 0) {
					cur ^= (1ll << (j - 1));
				}
				cur ^= (1ll << j);
				if (j + 1 < n) {
					cur ^= (1ll << (j + 1));
				}
			}
		}
		get[i] = cur;
	}


	int ans = 500;
	vector<int> ansb;

	for (int i = 0; i < (1 << n); i++) {
		vector<int> curb;
		vector<int> a2 = a;
		int cnt = c[i];
		a2[0] ^= get[i];
		if (n > 1) {
			a2[1] ^= i;
		}
		curb.push_back(i);

		for (int j = 1; j < n; j++) {
			int k = a2[j - 1];
			cnt += c[k];
			a2[j - 1] ^= k;
			a2[j] ^= get[k];
			curb.push_back(k);
			if (j + 1 < n) {
				a2[j + 1] ^= k;
			}
		}

		bool ok = 1;
		for (int j = 0; j < n; j++) {
			if (a2[j] != 0) {
				ok = 0;
			}
		}
		if (ok && cnt < ans) {
			ans = cnt;
			ansb = curb;
		}
	}

	for (int i = 0; i < n; i++) {
		a[i] = ((1 << n) - 1) ^ a[i];
	}

	int ans2 = 500;
	vector<int> answ;

	for (int i = 0; i < (1 << n); i++) {
		vector<int> curw;
		vector<int> a2 = a;
		int cnt = c[i];
		a2[0] ^= get[i];
		if (n > 1) {
			a2[1] ^= i;
		}
		curw.push_back(i);

		for (int j = 1; j < n; j++) {
			int k = a2[j - 1];
			cnt += c[k];
			a2[j - 1] ^= k;
			a2[j] ^= get[k];
			curw.push_back(k);
			if (j + 1 < n) {
				a2[j + 1] ^= k;
			}
		}

		bool ok = 1;
		for (int j = 0; j < n; j++) {
			if (a2[j] != 0) {
				ok = 0;
			}
		}
		if (ok && cnt < ans2) {
			ans2 = cnt;
			answ = curw;
		}
	}

	if (ans == 500 && ans2 == 500) {
		cout << -1 << '\n';
		return;
	}

	if (ans > ans2) {
		swap(ans, ans2);
		ansb.swap(answ);
	}

	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (((ansb[i] >> j) & 1) == 1) {
				cout << i + 1 << ' ' << j + 1 << '\n';
			}
		}
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