#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
#include <queue>
#include <random>
#include <cassert>

#define int long long
using namespace std;
mt19937 rng(58);

void solve() {
	int x = 210;

	int was = -1;
	while (1) {
		if (x >= 1000) {
			break;
		}
		int y = -1;
		if (was == -1) {
			for (int i = 1; i <= x; i++) {
				if (i + 2 * i + 4 * i + 8 * i <= x) {
					y = i;
				}
			}
		}
		else {
			y = was * 2;
		}
		cout << y << " R" << endl;
		int res;
		cin >> res;
		if (res == 0){
			x -= y;
			was = y;
		}
		else {
			x += y;
			was = -1;
		}
	}
}

signed main() {
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}