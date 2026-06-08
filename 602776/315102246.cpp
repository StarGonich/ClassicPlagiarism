#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <ios>
#include <iomanip>
#include <cmath>

#define int long long
#define ll long long

using namespace std;

void solve() {
	int n; cin >> n;
	
	vector<ll> x(n);
	vector<ll> d(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	int k; cin >> k; k--;

	int r = x[k] + d[k];
	int l = x[k] - d[k];
	set<int> used;
	for (int i = k; i < n; i++) {
		if (x[i] <= r) {
			used.insert(i);
			r = max(r, x[i] + d[i]);
			l = min(l, x[i] - d[i]);
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		if (x[i] >= l) {
			used.insert(i);
			r = max(r, x[i] + d[i]);
			l = min(l, x[i] - d[i]);
		}
	}
	for (int i = k; i < n; i++) {
		if (x[i] <= r) {
			used.insert(i);
			r = max(r, x[i] + d[i]);
			l = min(l, x[i] - d[i]);
		}
	}

	cout << used.size();
}

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
