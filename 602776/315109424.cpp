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
	ios::sync_with_stdio(0); cin.tie(false);
	//freopen("out.txt", "w", stdout);
	int c = 1;
	//cin >> c;
	while (c--) solve();
}

int a[200001];

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ind1 = -1;
	int l1 = 0;

	for (int i = 0; i < n; ++i) {
		if (a[i] == i + 1) continue;
		ind1 = i;
		break;
	}

	if (ind1 == -1) {
		cout << "-1";
		return;
	}

	int ind2 = -1;

	for (int i = ind1 + 1; i < n; ++i) {
		l1++;
		if (a[i] == a[i - 1] + 1) continue;
		if (a[i] > a[i - 1]) {
			cout << "-1";
			return;
		}

		ind2 = i;
		break;
	}

	if (ind2 == -1) {
		cout << "-1";
		return;
	}

	int l2 = 0;
	bool check = true;

	for (int i = ind2; i < n; ++i) {
		l2++;
		if (i > ind2 && a[i] != a[i - 1] + 1) {
			cout << "-1";
			return;
		}

		if (a[i] == a[ind1] - 1) {
			check = true;
			break;
		}
	}

	if (!check) {
		cout << "-1";
		return;
	}

	for (int i = ind2 + l2 + 1; i < n; ++i) {
		if (a[i] != a[i - 1] + 1) {
			cout << "-1";
			return;
		}
	}

	cout << ind1 + 1 << " " << l1 << "\n" << ind2 + 1 << " " << l2;
}