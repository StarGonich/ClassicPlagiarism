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
	ll a, b, p;
	cin >> a >> b >> p;
	ll c, d, q;
	cin >> c >> d >> q;

	if (a * d - c * b == 0) {
		if (q * a - c * p != 0) {
			cout << "Contradiction";
			return;
		}
		cout << "Ambiguity";
		return;
	}

	ld y = 100 * ld(q * a - c * p) / (a * d - c * b);


	ld x = 0;
	if (a != 0) {
		x = (100 * ld(p)-b * y) / a;
	}
	else {
		x = (100 * ld(q)-d * y) / c;
	}

	if (x > 0 && y > 0) {
		cout << "Success\n";
		cout << fixed << setprecision(10) << x << ' ' << y;
		return;
	}

	cout << "Not positive\n";
}
