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
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ind1 = -1;
	int len1 = 1;
	int ind2 = -1;
	int len2 = 1;

	for (int i = 0; i < n; i++) {
		if (v[i] != i + 1) {
			ind1 = i;
			break;
		}
	}

	if (ind1 == -1) {
		cout << -1 << '\n';
		return;
	}

	for (int i = ind1 + 1; i < n; i++) {
		if (v[i] != v[i - 1] + 1) {
			break;
		}
		else {
			len1++;
		}
	}

	for (int i = ind1 + len1; i < n; i++) {
		if (v[i] != i + 1) {
			ind2 = i;
			break;
		}
	}

	if (ind2 == -1) {
		cout << -1 << '\n';
		return;
	}

	for (int i = ind2 + 1; i < n; i++) {
		if (v[i] != v[i - 1] + 1) {
			break;
		}
		else {
			len2++;
		}
	}

	vector<int> ans;

	for (int i = 0; i < ind1; i++) {
		ans.push_back(v[i]);
	}
	for (int i = ind2; i < ind2 + len2; i++) {
		ans.push_back(v[i]);
	}
	for (int i = ind1 + len1; i < ind2; i++) {
		ans.push_back(v[i]);
	}
	for (int i = ind1; i < ind1 + len1; i++) {
		ans.push_back(v[i]);
	}
	for (int i = ind2 + len2; i < n; i++) {
		ans.push_back(v[i]);
	}

	if (is_sorted(ans.begin(), ans.end())) {
		cout << ind1 + 1 << ' ' << len1 << '\n';
		cout << ind2 + 1 << ' ' << len2;
	}
	else {
		cout << -1;
	}
}
