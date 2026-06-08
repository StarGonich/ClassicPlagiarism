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

void solve();
signed main() {
	//freopen("out.txt", "w", stdout);
	int c = 1;
	//cin >> c;
	while (c--) solve();
}

int x[100001];
int d[100001];

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	int k;
	cin >> k;

	k--;

	int ind = k;

	int l = x[ind] - d[ind];
	int r = x[ind] + d[ind];

	int ans = -1;

	while (ind >= 0) {
		if (x[ind] < l) break;
		ans++;
		l = min(x[ind] - d[ind], l);
		r = max(x[ind] + d[ind], r);
		ind--;
	}

	ind = k;

	while (ind < n) {
		if (x[ind] > r) break;
		ans++;
		r = max(x[ind] + d[ind], r);
		ind++;
	}

	cout << ans;
}