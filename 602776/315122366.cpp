#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

void solve();

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // _DEBUG


	// cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve();
	}
}

void solve() {
	int n, k, s, r, l;

	cin >> n;

	vector<int> arr(n);
	vector<int> res;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < n; ++i)
	{
		if (arr[i] < arr[i - 1]) {
			res.push_back(i);
		}
	}

	if (res.empty()) {
		cout << -1;
		return;
	}

	int s1 = res.back();
	int s2 = arr[s1] - 1;

	int l1 = 1;
	int l2 = 1;

	if (s1 < s2) {
		cout << -1;
		return;
	}

	for (int i = s1 + 1; i < n; ++i)
	{
		if (arr[i] - arr[i - 1] != 1) {
			break;
		}
		++l1;
	}

	for (int i = s2 + 1; i < s1; ++i)
	{
		if (arr[i] - arr[i - 1] != 1) {
			break;
		}
		++l2;
	}

	vector<int> answer(n);

	for (int i = 0; i < s2; ++i)
	{
		answer[i] = arr[i];
	}

	for (int i = 0; i < l1; ++i)
	{
		answer[s2 + i] = arr[s1 + i];
	}

	for (int i = 0; i < s1 - s2; ++i)
	{
		answer[s2 + l1 + i] = arr[s2 + l2 + i];
	}

	for (int i = 0; i < l2; ++i)
	{
		answer[s1 + l1 - l2 + i] = arr[s2 + i];
	}
	for (int i = s1 + l1; i < n; ++i)
	{
		answer[i] = arr[i];
	}
	for (int i = 1; i < n; ++i)
	{
		if (answer[i] < answer[i - 1]) {
			cout << -1;
			return;
		}
	}

	cout << s2 + 1 << " " << l2 << "\n" << s1 + 1 << " " << l1;
} 
