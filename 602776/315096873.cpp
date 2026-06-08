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

void solve() {
	int n;
	cin >> n;

	int cnt4 = n / 4;
	int cnt5 = n / 5;
	int cnt6 = n / 6;
	int cnt20 = n / 20;
	int cnt12 = n / 12;
	int cnt30 = n / 30;
	int cnt60 = n / 60;

	int ans = cnt4 + cnt5 + cnt6 - cnt20 * 2 - cnt12 * 2 - cnt30 * 2 + 3 * cnt60;

	cout << ans;
}