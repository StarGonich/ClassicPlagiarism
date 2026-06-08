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
	int n;
	cin >> n;

	vector<int> x(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	vector<int> d(n);

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	int k;
	cin >> k;

	k--;

	int l = x[k] - d[k];
	int r = x[k] + d[k];
	int lind = k;
	int rind = k + 1;
	bool was = true;
	int sch = 0;

	while (was) {
		was = false;

		int cl = l;
		int cr = r;

		while (lind >= 0 && x[lind] >= cl) {
			l = min(l, x[lind] - d[lind]);
			r = max(r, x[lind] + d[lind]);
			was = true;
			sch++;
			lind--;
		}

		while (rind < n && x[rind] <= cr) {
			l = min(l, x[rind] - d[rind]);
			r = max(r, x[rind] + d[rind]);
			was = true;
			sch++;
			rind++;
		}
	}

	cout << sch;
}
