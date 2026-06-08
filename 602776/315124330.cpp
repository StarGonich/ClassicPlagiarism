#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> rad(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> rad[i];
	}
	long long l, r;
	set<pair<int, int>> v;
	int k;
	cin >> k;
	k--;
	l = x[k] - rad[k];
	r = x[k] + rad[k];
	pair<int, int> left;
	pair<int, int> right;
	if (k > 0) {
		left = { x[k - 1] - x[k], k - 1 };
	}
	else
	{
		left = { 0, k };
	}
	if (k + 1 < n)
	{
		right = { x[k + 1] - x[k], k + 1 };
	}
	else
	{
		right = { 0, k };
	}
	int cnt = 1;
	int ll = k;
	int lr = k;
	while (true) {
		if (x[left.second] >= l && ll != left.second) {
			l = min(l, (long long)x[left.second] - rad[left.second]);
			r = max(r, (long long)x[left.second] + rad[left.second]);
			ll = left.second;
			cnt++;
			if (left.second > 0)
				left = { x[left.second - 1] - x[left.second], left.second - 1 };
		}
		else if (x[right.second] <= r && lr != right.second) {
			l = min(l, (long long)x[right.second] - rad[right.second]);
			r = max(r, (long long)x[right.second] + rad[right.second]);
			lr = right.second;
			cnt++;
			if (right.second + 1 < n)
				right = { x[right.second + 1] - x[right.second], right.second + 1 };
		}
		else {
			break;
		}
	}
	cout << cnt;
}