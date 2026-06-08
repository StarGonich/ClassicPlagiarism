#define _USE_MATH_DEFINES
#include <iostream>
#include <ios>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

#define ll long long
#define sortt(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())

struct fenwick {
	vector<int> t;
	int n;

	fenwick(int n_) : n(n_) {
		t.assign(n, 0);
	}

	int get(int i) {
		int sum = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1) sum += t[i];
		return sum;
	}

	void add(int i, int dif) {
		for (; i < n; i = i | (i + 1)) t[i] += dif;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	vector<int> d(n);
	for (int i = 0; i < n; i++) cin >> d[i];

	int res = 1;
	int k;
	cin >> k;
	k--;
	set<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		st.insert({ x[i], d[i] });
	}
	int minn = x[k] - d[k];
	int maxx = x[k] + d[k];
	st.erase({ x[k], d[k] });
	while (st.size()) {
		auto now = st.lower_bound({ minn, -1 });
		if (now == st.end() || now->first > maxx) break;

		int low = now->first - now->second;
		int hi = now->first + now->second;
		res++;
		minn = min(low, minn);
		maxx = max(hi, maxx);
		st.erase(now);
	}

	cout << res << endl;
}

int main()
{
	cout.tie(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	solve();
}
