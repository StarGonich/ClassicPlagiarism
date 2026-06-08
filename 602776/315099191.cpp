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

void solve() {
	int a, b, p, c, d, q;
	cin >> a >> b >> p >> c >> d >> q;
	int up = q * a - c * p;
	if (up == 0) {
		cout << "Ambiguity" << endl;
		return;
	}

	int low = d * a - b * c;
	if (low == 0) {
		cout << "Contradiction" << endl;
		return;
	}

	double y = (q * a - c * p) / (double) low;
	double x = (q - d * y) / (double)c;
	
	if (y < 0 || x < 0) {
		cout << "Not positive" << endl;
		return;
	}

	cout << "Success" << endl;
	cout << x * 100 << " " << y * 100 << endl;
}

int main()
{
	cout.tie(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	solve();
}
