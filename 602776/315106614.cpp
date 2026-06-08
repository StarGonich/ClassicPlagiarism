#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 engine(time(nullptr));

const int INF = 2 * 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-7;

void solve();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	/*cin >> t;*/
	t = 1;

	while (t--) {
		solve();
	}
}

void solve() {
	ll a, b, p, c, d, q;
	cin >> a >> b >> p >> c >> d >> q;

	if (b * c - d * a == 0) {
		ld x = 0;
		ld y = 0;
		if (b != 0) {
			y = ld(p) / b;
		}
		if (abs(ld(b) * y - p) >= EPS || abs(ld(d) * y - q) >= EPS) {
			cout << "Contradiction";
		}
		else {
			cout << "Ambiguity";
		}
		return;

	}

	ld x = 100 * ld(q * b - d * p) / (b * c - d * a);
	ld y = (100 * ld(p) - ld(a) * x) / b;

	if (x > EPS && y > EPS) {
		cout << "Success\n";
		cout << fixed << setprecision(10) << x << ' ' << y;
		return;
	}

	cout << "Not positive";
}
