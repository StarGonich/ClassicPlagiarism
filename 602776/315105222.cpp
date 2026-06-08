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

	int ans = -1;

	int l = x[k] - d[k];
	int r = x[k] + d[k];


	int lInd = k;
	int rInd = k;

	while (lInd >= 0 || rInd < n) {
		bool check = false;
		while (lInd >= 0) {
			if (x[lInd] < l) break;
			check = true;
			ans++;
			l = min(x[lInd] - d[lInd], l);
			r = max(x[lInd] + d[lInd], r);
			lInd--;
		}

		while (rInd < n) {
			if (x[rInd] > r) break;
			check = true;
			ans++;
			l = min(x[rInd] - d[rInd], l);
			r = max(x[rInd] + d[rInd], r);
			rInd++;
		}

		if (!check) break;
	}

	cout << ans;
}