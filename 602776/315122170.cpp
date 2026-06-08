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
	if (k > 0) {
		v.insert({ x[k - 1] - x[k], k - 1 });
	}
	if (k + 1 < n)
	{
		v.insert({ x[k + 1] - x[k], k + 1 });
	}
	int cnt = 1;
	while (!v.empty()) {
		auto& s = *v.begin();
		if (s.first < 0 && x[s.second] >= l) {
			l = min(l, (long long)x[s.second] - rad[s.second]);
			r = max(r, (long long)x[s.second] + rad[s.second]);
			cnt++;
			if (s.second > 1)
				v.insert({ x[s.second - 1] - x[s.second], s.second - 1 });
		}
		else if (s.first > 0 && x[s.second] <= r) {
			l = min(l, (long long)x[s.second] - rad[s.second]);
			r = max(r, (long long)x[s.second] + rad[s.second]);
			cnt++;
			if (s.second + 1 < n)
				v.insert({ x[s.second + 1] - x[s.second], s.second + 1 });
		}
		v.erase(v.begin());
	}
	cout << cnt;
}