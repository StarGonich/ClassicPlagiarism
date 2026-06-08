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
	vector<ll> v(n + 3); 
	v[0] = 0; v[n + 1] = n + 1; v[n + 2] = n + 2;
	for (int i = 1; i <= n; ++i) cin >> v[i];
	vector<ll> sm(n + 3);
	for (int i = 0; i <= n + 2; ++i) {
		sm[i] = v[i] - i;
	}
	set<ll> rz;
	for (auto& e : sm) {
		if (e != 0) rz.insert(e);
	}
	if (rz.size() != 2) {
		cout << -1;
		return;
	}
	vector<ll> zz;
	for (int i = 0; i <= n + 1; ++i) {
		if (sm[i] != sm[i + 1]) zz.push_back(sm[i]);
	}zz.push_back(0);
	vector<ll> zz2;
	for (auto& e : zz) if (e != 0) zz2.push_back(e);
	if (zz2.size() != 2) {
		cout << -1;
		return;
	}
	vector<ll> v2(n + 3);
	for (int i = 1; i <= n; ++i) {
		v2[i] = v[i] - sm[i];
		if (v2[i] != i) {
			cout << -1;
			return;
		}
	}

	ll n1 = 0, zsm1 = 0;
	for (int i = 1; i <= n; ++i) {
		if (sm[i] != 0) {
			n1 = i;
			zsm1 = sm[i];
			break;
		}
	}
	ll nn1 = n1;
	while (sm[n1] == zsm1) n1++;
	cout << nn1 << " " << n1 - nn1 << "\n";

	ll n2 = 0, zsm2 = 0;
	for (int i = n1; i <= n; ++i) {
		if (sm[i] != 0) {
			n2 = i;
			zsm2 = sm[i];
			break;
		}
	}
	ll nn2 = n2;
	while (sm[n2] == zsm2) n2++;
	cout << nn2 << " " << n2 - nn2 << "\n";
} 