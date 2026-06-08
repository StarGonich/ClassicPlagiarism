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

#include <queue>
using namespace std;

#define ll long long
#define sortt(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define pb push_back

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

const int inf = 2e18;

vector<pair<pair<int, int>, int>> g[1000][101];
pair<int, int> from[1000][101];
int dp[1000][101];

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> cost(n);
	for (int i = 0; i < n; i++) cin >> cost[i];

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		for (int level = 0; level <= 100; level++) {
			g[u][level].pb({ {v, level}, w});
			g[v][level].pb({ {u, level}, w});

			if (level > cost[v]) g[u][level].pb({{ v, cost[v]}, w});
			if (level > cost[u]) g[v][level].pb({ { u, cost[u]}, w });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int c = 0; c <= 100; c++) dp[i][c] = inf;
	}
	
	priority_queue<tuple<int, pair<int, int>, pair<int, int>>> q;
	q.push({ 0, {0, cost[0]}, {-1, -1} });
	while (q.size()) {
		auto p = q.top(); q.pop();

		int dpwas = -get<0>(p);
		pair<int, int > nowpair = get<1>(p);
		int costnow = nowpair.second;
		int posnow = nowpair.first;

		pair<int, int> frompair = get<2>(p);

		if (dp[posnow][costnow] != inf) continue;
		from[posnow][costnow] = frompair;
		dp[posnow][costnow] = dpwas;

		for (auto to : g[posnow][costnow]) {
			pair<int, int> topair = to.first;
			int tow = to.second;

			int costgo = dpwas + costnow * tow;
			q.push({ -costgo, topair,  nowpair });
		}
	}

	pair<int, int> now;
	int costnow = inf;
	for (int c = 0; c <= 100; c++) {
		if (dp[n - 1][c] < costnow) {
			costnow = dp[n - 1][c];
			now = { n - 1, c };
		}
	}

	if (costnow == inf) {
		cout << -1 << endl;
		return;
	}

	int filled = 0;
	int costall = 0;
	vector<pair<int, int>> ans;
	while (now.first != 0) {
		pair<int, int> parent = from[now.first][now.second];
		costall += dp[now.first][now.second] - dp[parent.first][parent.second];
		int fillnow = 0;
		if (now.second != parent.second) {
			fillnow = filled / now.second;
			filled = 0;
		}
		ans.pb({ now.first + 1, fillnow });
		filled += dp[now.first][now.second] - dp[parent.first][parent.second];
		now = parent;
	}
	ans.pb({ now.first + 1, filled / now.second });


	cout << costall << "\n";
	rev(ans);
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << "\n";
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
