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

const double eps = 1e-6;

void solve() {
	int a, b, p;
	int c, d, q;
	cin >> a >> b >> p;
	cin >> c >> d >> q;

	p *= 100;
	q *= 100;

	if (a == 0) {
		double y = p * 1.0 / b;
		double pp = (q - d * y);
		double qq = c;
		if (abs(pp) < eps && abs(qq) < eps) {
			cout << "Ambiguity";
			return;
		}
		if (abs(qq) < eps) {
			cout << "Contradiction";
			return;
		}
		double x = pp / qq;
		if (x < 0 || y < 0) {
			cout << "Not positive\n";
			return;
		}
		cout << "Success\n";
		cout << x << ' ' << y << '\n';
		return;
	}

	double pp = (q - c * p * 1.0 / a);
	double qq = (d - b * c * 1.0 / a);
	if (abs(pp) < eps && abs(qq) < eps) {
		cout << "Ambiguity";
		return;
	}
	if (abs(qq) < eps) {
		cout << "Contradiction";
		return;
	}
	double y = pp / qq;
	double x = (p - b * y) / a;
	if (x < 0 || y < 0) {
		cout << "Not positive\n";
		return;
	}
	cout << "Success\n";
	cout << x << ' ' << y << '\n';
}

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}