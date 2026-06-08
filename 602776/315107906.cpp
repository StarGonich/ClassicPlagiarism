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

ll fastPow(int a, int p, int m) {
	if (p == 0) return 1;
	if (p == 1) return a % m;

	if (p % 2 == 0) {
		ll res = fastPow(a, p / 2, m);
		return (res * res) % m;
	}
	else {
		ll res = fastPow(a, p / 2, m);
		return (((res * res) % m) * a) % m;
	}
}

void solve() {
	int n; cin >> n;

	int mod = 1e9 + 7;

	ll res = (((n - 3) * fastPow(2, n - 4, mod)) % mod + fastPow(2, n - 3, mod) + fastPow(2, n - 3, mod)) % mod;

	cout << res;
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
