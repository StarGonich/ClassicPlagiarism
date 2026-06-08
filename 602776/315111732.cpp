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

int M = 1e9 + 7;


void solve() {
	int sum = 210;

	while (sum < 1000) {
		int bet = sum / 15;

		for (int bets = 1; ; bets *= 2) {
			cout << bet * bets << " R" << endl;
			cout.flush();
			int ans;
			cin >> ans;
			if (ans == -1) break;
			if (ans == 1) {
				sum += bet * bets;
				break;
			}
			else {
				sum -= bet * bets;
			}
		}
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
