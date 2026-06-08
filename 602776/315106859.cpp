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

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> sorted(n);
	for (int i = 1; i <= n; i++) {
		sorted[i - 1] = i;
	}

	int left_ptr = 0;
	while (left_ptr < n && a[left_ptr] == sorted[left_ptr]) {
		left_ptr++;
	}
	if (left_ptr == n) {
		cout << -1;
		return;
	}

	int ptr1 = left_ptr;
	while (left_ptr + 1 < n && a[left_ptr + 1] == a[left_ptr] + 1) {
		left_ptr++;
	}
	int len1 = left_ptr - ptr1 + 1;

	int right_ptr = n-1;
	while (right_ptr >= 0 && a[right_ptr] == sorted[right_ptr]) {
		right_ptr--;
	}

	int ptr2 = right_ptr;
	while (right_ptr - 1 >= 0 && a[right_ptr - 1] == a[right_ptr] - 1) {
		right_ptr--;
	}
	int len2 = ptr2 - right_ptr + 1;
	ptr2 = ptr2 - len2 + 1;

	int sort_ptr = 0;
	for (int i = 0; i < ptr1; i++) {
		if (a[i] != sorted[sort_ptr]) {
			cout << -1;
			return;
		}
		sort_ptr++;
	}
	for (int i = ptr2; i < ptr2 + len2; i++) {
		if (a[i] != sorted[sort_ptr]) {
			cout << -1;
			return;
		}
		sort_ptr++;
	}
	for (int i = ptr1 + len1; i < ptr2; i++) {
		if (a[i] != sorted[sort_ptr]) {
			cout << -1;
			return;
		}
		sort_ptr++;
	}
	for (int i = ptr1; i < ptr1 + len1; i++) {
		if (a[i] != sorted[sort_ptr]) {
			cout << -1;
			return;
		}
		sort_ptr++;
	}
	for (int i = ptr2 + len2; i < n; i++) {
		if (a[i] != sorted[sort_ptr]) {
			cout << -1;
			return;
		}
		sort_ptr++;
	}

	cout << ptr1 + 1 << " " << len1 << "\n";
	cout << ptr2 + 1 << " " << len2 << "\n";
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
