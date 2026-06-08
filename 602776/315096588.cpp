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
	ll c4 = n / 4;
	ll c5 = n / 5;
	ll c6 = n / 6;
	cout << (c4 - (n / 20) - (n / 12)) +
		(c5 - (n / 20) - (n / 30)) +
		(c6 - (n / 30) - (n / 12));
}