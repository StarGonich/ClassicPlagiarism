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
typedef long double ld;

const ld EPS = 1e-5;

void solve();

int main() {
#ifndef ONLINE_JUDGE
	FILE* FILE_IN = freopen("input.txt", "r", stdin);
	FILE* FILE_OUT = freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(3);
	ll t_t_t = 1; 
	// cin >> t_t_t;
	while (t_t_t--) {
		solve();
	}
}

void solve() {
	ll n; cin >> n;
	vector<ll> v(n + 2); 
	v[n + 1] = n + 1;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}

	vector<ll> ans;

	ll j = 0;
	for (int i = 0; i <= n; ++i) {
		if (v[i] != i) {
			j = i;
			break;
		}
	}
	if (j == 0) {
		cout << -1;
		return;
	}
	ans.push_back(j);
	ll z = v[j] - j;
	while (v[j] - (j) == z) {
		v[j] = j;
		j++;
	}
	ans.push_back(j);

	j = 0;
	for (int i = 0; i <= n; ++i) {
		if (v[i] != i) {
			j = i;
			break;
		}
	}
	if (j == 0) {
		cout << -1;
		return;
	}
	ans.push_back(j);
	z = v[j] - j;
	while (v[j] - (j) == z) {
		v[j] = j;
		j++;
	}
	ans.push_back(j);

	auto cp = v;
	sort(cp.begin(), cp.end());
	if (cp != v) {
		cout << -1;
		return;
	}

	cout << ans[0] << " " << ans[1] - ans[0] << "\n";
	cout << ans[2] << " " << ans[3] - ans[2] << "\n";
} 