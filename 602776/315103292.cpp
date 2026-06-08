#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <ios>
#include <iomanip>
#include <cmath>

#define int long long
#define ll long long

using namespace std;

void solve() {
	int n; cin >> n;
	
	vector<ll> x(n);
	vector<ll> d(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	int k; cin >> k; k--;

	int r = x[k] + d[k];
	int l = x[k] - d[k];
	int cnt = 1;

	int left_ptr = k - 1;
	int right_ptr = k + 1;
	while (true) {
		if (left_ptr < 0 && right_ptr >= n) {
			cout << cnt;
			return;
		}
		if (left_ptr >= 0 && right_ptr < n && x[left_ptr] < l && x[right_ptr] > r) {
			cout << cnt;
			return;
		}
		if (left_ptr < 0 && right_ptr < n && x[right_ptr] > r) {
			cout << cnt;
			return;
		}
		if (left_ptr >= 0 && right_ptr >= n && x[left_ptr] < l) {
			cout << cnt;
			return;
		}
		if (right_ptr < n && x[right_ptr] <= r) {
			cnt++;
			r = max(r, x[right_ptr] + d[right_ptr]);
			l = min(l, x[right_ptr] - d[right_ptr]);
			right_ptr++;
		}
		if (left_ptr >= 0 && x[left_ptr] >= l) {
			cnt++;
			r = max(r, x[left_ptr] + d[left_ptr]);
			l = min(l, x[left_ptr] - d[left_ptr]);
			left_ptr--;
		}
	}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}
