#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-5;

int main() {
#ifndef ONLINE_JUDGE
	//FILE* FILE_IN = freopen("input.txt", "r", stdin);
	//FILE* FILE_OUT = freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr); cout.tie(nullptr);
	//cout << fixed << setprecision(3);
	ll m = 210;
	ll looses = 0;
	ll cnt = 0;
	ll z = 0;
	while (m < 1000 && cnt < 100) {
		ll st = 0;
		if (looses == 0) {
			z = m;
			st = m / 25;
		}
		if (looses == 1) st = z / 25 * 3;
		if (looses == 2) st = z / 25 * 7;
		if (looses == 3) st = m;
		cout << st << " B" << endl;
		ll ans; cin >> ans;
		if (ans == -1) return 0;
		if (ans == 0) {
			looses++;
			m -= st;
		}
		else {
			looses = 0;
			m += st;
		}
		cnt++;
	}
}