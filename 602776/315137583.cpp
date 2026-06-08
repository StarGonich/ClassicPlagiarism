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

	vector<ll> pows(1000000 + 1);
	for (int i = 1; i <= 1000000; i++) {
		pows[i] = i * i;
	}

	vector<ll> pref(1000000 + 1);
	pref[0] = pows[0];
	for (int i = 1; i <= 1000000; i++) {
		pref[i] = pref[i - 1] + pows[i];
	}

	for (int i = 0; i <= 1000000; i++) {
		int j = i + n;
		if ((int)sqrt(pref[j] - pref[i]) * (int)sqrt(pref[j] - pref[i]) == pref[j] - pref[i]) {
			for (int k = i+1; k <= j; k++) {
				cout << k << " ";
			}
			cout << (int)sqrt(pref[j] - pref[i]);
			return;
		}
	}

	cout << -1;
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
