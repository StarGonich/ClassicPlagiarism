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

using namespace std;

int c[1 << 20];
int gt[1 << 20];

int a[20];
int a2[20];

void solve() {
	int n;
	cin >> n;
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

	for (int i = 1; i < (1 << n); i++) {
		c[i] = c[i >> 1] + (i & 1);
	}

	for (int i = 0; i < (1 << n); i++) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1) == 1) {
				if (j - 1 >= 0) {
					cur ^= (1 << (j - 1));
				}
				cur ^= (1 << j);
				if (j + 1 < n) {
					cur ^= (1 << (j + 1));
				}
			}
		}
		gt[i] = cur;
	}


	int ans = 500;
	int maskb = -1;

	for (int i = 0; i < (1 << n); i++) {
		memcpy(a2, a, sizeof(a));
		int cnt = c[i];
		a2[0] ^= gt[i];
		if (n > 1) {
			a2[1] ^= i;
		}

		for (int j = 1; j < n; j++) {
			if (cnt > ans) {
				break;
			}
			int k = a2[j - 1];
			cnt += c[k];
			a2[j - 1] ^= k;
			a2[j] ^= gt[k];
			if (j + 1 < n) {
				a2[j + 1] ^= k;
			}
		}
		if (a2[n - 1] == 0 && cnt < ans) {
			ans = cnt;
			maskb = i;
		}
	}

	for (int i = 0; i < n; i++) {
		a[i] = ((1 << n) - 1) ^ a[i];
	}

	int ans2 = 500;
	int maskw = -1;

	for (int i = 0; i < (1 << n); i++) {
		memcpy(a2, a, sizeof(a));
		int cnt = c[i];
		a2[0] ^= gt[i];
		if (n > 1) {
			a2[1] ^= i;
		}

		for (int j = 1; j < n; j++) {
			if (cnt > ans) {
				break;
			}
			int k = a2[j - 1];
			cnt += c[k];
			a2[j - 1] ^= k;
			a2[j] ^= gt[k];
			if (j + 1 < n) {
				a2[j + 1] ^= k;
			}
		}
		if (a2[n - 1] == 0 && cnt < ans2) {
			ans2 = cnt;
			maskw = i;
		}
	}

	if (ans == 500 && ans2 == 500) {
		cout << -1 << '\n';
		return;
	}

	if (ans < ans2) {
		for (int i = 0; i < n; i++) {
			a[i] = ((1 << n) - 1) ^ a[i];
		}
		cout << ans << '\n';

		int i = maskb;
		memcpy(a2, a, sizeof(a));
		int cnt = c[i];
		a2[0] ^= gt[i];
		if (n > 1) {
			a2[1] ^= i;
		}
		for (int l = 0; l < n; l++) {
			if (((i >> l) & 1) == 1) {
				cout << 1 << ' ' << l + 1 << '\n';
			}
		}

		for (int j = 1; j < n; j++) {
			if (cnt > ans) {
				break;
			}
			int k = a2[j - 1];
			cnt += c[k];
			a2[j - 1] ^= k;
			a2[j] ^= gt[k];
			if (j + 1 < n) {
				a2[j + 1] ^= k;
			}
			for (int l = 0; l < n; l++) {
				if (((k >> l) & 1) == 1) {
					cout << j + 1 << ' ' << l + 1 << '\n';
				}
			}
		}
	}
	else {
		cout << ans2 << '\n';
		int i = maskw;
		memcpy(a2, a, sizeof(a));
		int cnt = c[i];
		a2[0] ^= gt[i];
		if (n > 1) {
			a2[1] ^= i;
		}
		for (int l = 0; l < n; l++) {
			if (((i >> l) & 1) == 1) {
				cout << 1 << ' ' << l + 1 << '\n';
			}
		}

		for (int j = 1; j < n; j++) {
			if (cnt > ans) {
				break;
			}
			int k = a2[j - 1];
			cnt += c[k];
			a2[j - 1] ^= k;
			a2[j] ^= gt[k];
			if (j + 1 < n) {
				a2[j + 1] ^= k;
			}
			for (int l = 0; l < n; l++) {
				if (((k >> l) & 1) == 1) {
					cout << j + 1 << ' ' << l + 1 << '\n';
				}
			}
		}
	}
}

signed main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}