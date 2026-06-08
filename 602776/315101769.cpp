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
	double a, b, p, c, d, q;
	cin >> a >> b >> p >> c >> d >> q;

	if (b < 1e-6 && d < 1e-6 && abs(p / a - q / c) < 1e-6) {
		cout << "Ambiguity";
		return;
	}

	else if (b < 1e-6 && d < 1e-6) {
		cout << "Contradiction";
		return;
	}

	double first = (b * c) / a - d;
	double second = (p * c) / a - q;

	double y = second / first;

	if (a < 1e-6) y = p / b;
	if (c < 1e-6) y = q / d;

	if (a < 1e-6 && c < 1e-6 && abs(p / b - q / d) < 1e-6) {
		cout << "Ambiguity";
		return;
	}

	else if (a < 1e-6 && c < 1e-6) {
		cout << "Contradiction";
		return;
	}

	if (abs(first) < 1e-6 && abs(p - q) < 1e-6) {
		cout << "Ambiguity";
		return;
	}

	else if (abs(first) < 1e-6) {
		cout << "Contradiction";
		return;
	}

	double x = (q - d * y) / c;

	if (b < 1e-6) x = p / a;
	if (d < 1e-6) x = q / c;



	if (x < 0 || y < 0) {
		cout << "Not positive";
		return;
	}

	cout << "Success\n";

	cout << setprecision(3) << fixed;
	cout << x * 100 << " " << y * 100;
}