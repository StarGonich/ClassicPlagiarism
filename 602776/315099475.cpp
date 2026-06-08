#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

void solve();

int main() {
#ifndef ONLINE_JUDGE
	FILE* FILE_IN = freopen("input.txt", "r", stdin);
	FILE* FILE_OUT = freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll t_t_t = 1; 
	// cin >> t_t_t;
	while (t_t_t--) {
		solve();
	}
}

void solve() {
	ll n; cin >> n;
	vector<ll> x(n + 2, 0);
	x[0] = -1e10; x[n + 1] = 1e10;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	vector<ll> d(n + 2, 0);
	for (int i = 1; i <= n; ++i) cin >> d[i];
	ll k; cin >> k;
	ll cnt = 1;
	ll maX = x[k] + d[k];
	ll miX = x[k] - d[k];
	ll i = k + 1, j = k - 1;
	while (x[i] <= maX || x[j] >= miX) {
		if (x[i] <= maX) {
			cnt++;
			maX = max(maX, x[i] + d[i]);
			miX = min(miX, x[i] - d[i]);
			i++;
		}
		if (x[j] >= miX) {
			cnt++;
			maX = max(maX, x[j] + d[j]);
			miX = min(miX, x[j] - d[j]);
			j--;
		}
	}
	cout << cnt;
}