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
	//ios::sync_with_stdio(0); cin.tie(false);
	//freopen("out.txt", "w", stdout);
	int c = 1;
	//cin >> c;
	while (c--) solve();
}


void solve() {
	int s = 210;

	int stavka = s / 15;

	while (s < 1000) {
		cout << stavka << " R" << endl;
		int ans;
		cin >> ans;

		if (ans == 0) {
			s -= stavka;
			stavka *= 2;
		}

		else {
			s += stavka;
			stavka = s / 15;
		}
	}
}