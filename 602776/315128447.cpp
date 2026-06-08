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
	//FILE* FILE_IN = freopen("input.txt", "r", stdin);
	//FILE* FILE_OUT = freopen("output.txt", "w", stdout);
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
	ll m = 210;
	ll looses = 0;
	while (m < 1000) {
		char cl = (rand() % 2) ? 'B' : 'R';
		ll st = 0;
		if (looses == 0) st = 14;
		if (looses == 1) st = 28;
		if (looses == 2) st = 56;
		if (looses == 3) st = m;
		cout << st;
		cout << ' ' << cl;
		cout << endl;
		cout << flush;
		ll ans; cin >> ans;
		if (ans == -1) return;
		if (ans == 0) {
			looses++;
			m -= st;
		}
		else {
			looses = 0;
			m += st;
		}
	}
} 