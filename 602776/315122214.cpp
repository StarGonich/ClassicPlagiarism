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

	vector<pair<ll, ll>> pl = { {0,0} };
	for (int i = 1; i <= n + 1; ++i) {
		if (v[i] != v[i - 1] + 1) {
			pl.push_back({ v[i], v[i] });
		}
		else {
			pl.back().second++;
		}
	}
	if (pl.size() == 4) {
		cout << pl[1].second + 1 << " " << pl[1].second - pl[1].first + 1 << "\n";
		cout << pl[1].first + 1 << " " << pl[2].second - pl[2].first + 1 << "\n";
	}
	else if (pl.size() == 5) {
		cout << pl[3].first << " " << pl[1].second - pl[1].first + 1 << "\n";
		cout << pl[2].second - pl[2].first + 1 + pl[1].second - pl[1].first + 1 + 1 << " " <<
			pl[3].second - pl[3].first + 1 << "\n";
	}
	else {
		cout << -1;
	}
} 