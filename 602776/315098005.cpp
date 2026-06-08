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
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	int k;
	cin >> k;
	k--;
	int ans = 1;

	int l = x[k] - d[k], r = x[k] + d[k];
	int u = k - 1, v = k + 1;
	while (1) {
		if (u >= 0 && x[u] >= l) {
			ans++;
			l = min(l, x[u] - d[u]);
			r = max(r, x[u] + d[u]);
			u--;
		}
		else if (v < n && x[v] <= r) {
			ans++;
			l = min(l, x[v] - d[v]);
			r = max(r, x[v] + d[v]);
			v++;
		}
		else {
			break;
		}
	}
	cout << ans << '\n';
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