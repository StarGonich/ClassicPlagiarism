#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <algorithm>
#include <queue>
#include <random>
#include <cassert>

#define int long long
using namespace std;
mt19937 rng(58);

const int INF = 1e12;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int f, t, c;
		cin >> f >> t >> c;
		f--;
		t--;
		g[f].emplace_back(t, c);
		g[t].emplace_back(f, c);
	}

	vector<vector<int>> dp(n, vector<int>(101, INF));
	vector<vector<pair<int, int>>> pred(n, vector<pair<int, int>>(101, { INF, INF }));

	dp[0][a[0]] = 0;
	set<tuple<int, int, int>> st;
	st.insert({ 0, a[0], 0 });

	while (!st.empty()) {
		auto e = *st.begin();
		st.erase(st.begin());
		int d = get<0>(e);
		int mn = get<1>(e);
		int v = get<2>(e);

		for (auto edge : g[v]) {
			int to = edge.first;
			int cost = edge.second * mn;
			if (dp[to][min(a[to], mn)] > dp[v][mn] + cost) {
				st.erase({ dp[to][min(a[to], mn)], min(a[to], mn), to });
				dp[to][min(a[to], mn)] = dp[v][mn] + cost;
				pred[to][min(a[to], mn)] = { v, mn };
				st.insert({ dp[to][min(a[to], mn)], min(a[to], mn), to });
			}
		}
	}

	int mn = 100;
	int val = INF;
	for (int i = 1; i <= 100; i++) {
		if (dp[n - 1][i] < val) {
			val = dp[n - 1][i];
			mn = i;
		}
	}

	if (val == INF) {
		cout << -1 << '\n';
		return;
	}

	vector<int> path;

	int v = n - 1;
	while(v != INF){
		path.push_back(v);
		int cur = v;
		v = pred[v][mn].first;
		mn = pred[cur][mn].second;
	}

	reverse(path.begin(), path.end());

	vector<int> need(n);
	v = 0;
	for (int i = 0; i < path.size() - 1; i++) {
		int bb = INF;
		for (auto edge : g[path[i]]) {
			if (edge.first == path[i + 1]) {
				bb = min(bb, edge.second);
			}
		}
		need[v] += bb;
		if (a[v] > a[path[i + 1]]) {
			v = path[i + 1];
		}
	}

	cout << val << '\n';
	cout << path.size() << '\n';
	int su = 0;
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] + 1 << ' ' << need[path[i]] << '\n';
		su += a[path[i]] * need[path[i]];
	}
	assert(su == val);
}

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}