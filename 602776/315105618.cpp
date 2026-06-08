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
	int s1 = 0, s2 = 0, f1 = 0, f2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			if (!s1) {
				s1 = i + 1;
				f1 = i + 1;
			}
			else if (f1 == i && a[i] == a[i - 1] + 1) {
				f1++;
			}
			else if (!s2) {
				s2 = i + 1;
				f2 = i + 1;
			}
			else if (f2 == i && a[i] == a[i - 1] + 1) {
				f2++;
			}
			else {
				cout << -1 << endl;
				return;
			}
		}
	}

	if (s1 && s2) {
		cout << s1 << " " << f1 - s1 + 1 << endl << s2 << " " << f2 - s2 + 1 << endl;
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
