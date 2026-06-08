#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <bitset>
#include <random>
#include <ctime>

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;

mt19937_64 rng(time(NULL));

ll d2[1000001];

void solve();
signed main() {
	ios::sync_with_stdio(0); cin.tie();
	//freopen("out.txt", "w", stdout);

	d2[0] = 1;

	for (ll i = 1; i <= 1000000; ++i) {
		d2[i] = d2[i - 1] * 2;
		d2[i] %= mod;
	}

	int c = 1;
	//cin >> c;
	while (c--) solve();
}

void solve() {
	int n;
	cin >> n;
	

	ll ans = 0;

	for (int i = 1; i < n; ++i) {
		int lCnt = max(0, i - 2);
		int rCnt = max(0, n - i - 2);

		ll curr = d2[lCnt] * d2[rCnt];
		curr %= mod;

		ans += curr;
		ans %= mod;
	}

	cout << ans;
}