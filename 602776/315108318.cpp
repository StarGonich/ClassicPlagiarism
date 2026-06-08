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
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	map<int, int> pos;
	for (int i = 0; i < n; i++) pos[a[i]] = i;

	int s1 = 0, s2 = 0, f1 = 0, f2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == i + 1) continue;
		s1 = pos[i + 1];
		int len = 1;
		while (len + s1 < n && a[s1 + len] == 1 + a[s1 + len - 1]) len++;
		f1 = s1 + len - 1;
		s1++;
		f1++;
		s2 = i;
		f2 = i;
		while (f2 + 1 < n && a[f2 + 1] == 1 + a[f2]) f2++;
		s2++;
		f2++;
		swap(f1, f2);
		swap(s1, s2);
		break;
	}


	if (s1 > 0 && s2 > 0) {
		vector<int> res;

		for (int i = 0; i < s1 - 1; i++) res.push_back(a[i]);
		for (int i = s2 - 1; i < f2; i++) res.push_back(a[i]);
		for (int i = f1; i < s2 - 1; i++) res.push_back(a[i]);
		for (int i = s1 - 1; i < f1; i++) res.push_back(a[i]);
		for (int i = f2; i < n; i++) res.push_back(a[i]);

		bool ok = 1;
		for (int i = 0; i < n; i++) ok = (res[i] == i + 1) && ok;

		if (ok) cout << s1 << " " << f1 - s1 + 1 << endl << s2 << " " << f2 - s2 + 1 << endl;
		else cout << -1 << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main()
{
	cout.tie(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	solve();
}
