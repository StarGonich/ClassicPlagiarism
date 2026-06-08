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

	d2[0] = 0;

	int c = 1;
	//cin >> c;
	while (c--) solve();
}

ll getOdd(ll l, ll r) {
	if (l > r) return 0;

	ll res = 0;

	if (l % 2 == 1) {
		res++;
		l++;
	}

	if (r % 2 == 1) {
		res++;
		r--;
	}

	res += (r - l) / 2;
	return res;
}

ll getEven(ll l, ll r) {
	if (l > r) return 0;

	ll res = 0;

	if (l % 2 == 0) {
		res++;
		l++;
	}

	if (r % 2 == 0) {
		res++;
		r--;
	}

	res += (r - l) / 2;
	return res;
}

void solve() {
	int n;
	cin >> n;
	

	ll ans = 0;

	for (int i = 1; i < n; ++i) {
		ll lCnt = d2[getOdd(1, i - 2)] + d2[getEven(1, i - 2)];
		if (!lCnt) lCnt++;
		lCnt %= mod;


		ll rCnt = d2[getOdd(i + 3, n)] + d2[getEven(i + 3, n)];
		if (!rCnt) rCnt++;
		rCnt %= mod;

		ll curr = lCnt * rCnt;
		curr %= mod;

		ans += curr;
		ans %= mod;
	}

	cout << ans;
}